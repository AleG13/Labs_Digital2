
#include <SPI.h>
#include <SD.h>
File root;

File myFile;
File myFile2;
String opcion = "";

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("\n /////////MENÚ//////////");
  SPI.setModule(0);
  
  Serial.print("Initializing SD card...");

  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

 
}

void loop()
{
   Serial.println("Elija la opción de su preferencia:");
   Serial.println("1 - Leer Archivo");
   Serial.println("2 - Escribir Archivo");
   opcion = leerfrase();
   
   if(opcion == "1"){
    Serial.println("\n Elija el Archivo de su preferencia:");
   
               root = SD.open("/");
               printDirectory(root, 0);
               opcion = leerfrase();
               char miArray[opcion.length() + 1]; // +1 para el carácter nulo '\0'
            
                opcion.toCharArray(miArray, opcion.length() + 1);
                myFile = SD.open(miArray);
            
                if (myFile) {
                Serial.println("\n File:");
            
                // read from the file until there's nothing else in it:
                while (myFile.available()) {
                  Serial.write(myFile.read());
                }
                // close the file:
                myFile.close();
              } else {
                // if the file didn't open, print an error:
                Serial.println("error opening File");
              }
                 
   }
   else if(opcion == "2"){
      Serial.println("Ingresa el nombre del Nuevo archivo: ");
      String fileName = leerfrase();
      String ext = ".txt";
      String fileName2;
      fileName2.concat(fileName);
      fileName2.concat(ext);
      
      char miArray[fileName2.length() + 1]; // +1 para el carácter nulo '\0'
      myFile2 = SD.open("prueba30.txt", FILE_WRITE);
    
      // if the file opened okay, write to it:
      if (myFile2) {
        Serial.print("Writing to test.txt...");
        Serial.println("Ingrese la Información que desea guardar: ");
        String fileData= leerfrase();
        char miData[fileData.length() + 1]; // +1 para el carácter nulo '\0'
        myFile2.println(fileData);
        // close the file:
        myFile2.close();
        Serial.println("done.");
      } else {
        // if the file didn't open, print an error:
        Serial.println("error opening file");
      }
   }
    else{
     Serial.println("INVALIDO!! Vuelva a elegir");
   }
}
void readFile(){
   // re-open the file for reading:
 
  myFile = SD.open("Name");
  if (myFile) {
    Serial.println("File:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening File");
  }
}
void writeFile(){
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("menu.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to File...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
String leerfrase () //función que devuelve cadena
 {
   while (Serial.available()==0);  //bloquea hasta que escriba
   delay (20); //da tiempo para que lleguen todos los caracteres al buffer 
   String inString = ""; //almacenamiento externo del buffer
   while (Serial.available() > 0) //mientras haya caracteres en el buffer Serial
   {
   int inChar = Serial.read(); //lee carácter
   if (inChar == '\n' || inChar == '\r' )  //si último caracter (nulo) o retorno
   {inString = inString;} //quitarlo para que haya no doble salto línea o retorno 
   else {inString = inString + (char)inChar;} //añádelo a la cadena
   }
 return inString;  //devuelve frase
 }

  
void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
