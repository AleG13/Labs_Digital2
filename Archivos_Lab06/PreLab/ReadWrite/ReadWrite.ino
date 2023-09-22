/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;
String opcion = "";

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("/////////MENÚ//////////");
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
   Serial.println("Elija la opción de su preferencia:");
   opcion = leerfrase();
   Serial.println(opcion);
   readFile(fileName)
}
void readFile(fileName){
   // re-open the file for reading:
  myFile = SD.open(fileName);
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
