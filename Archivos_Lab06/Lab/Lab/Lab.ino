
#include <SPI.h>
#include <SD.h>
File root;
File myFile;
String opcion = "";
String fileName = "";
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
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
 
}

void loop()
{
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
