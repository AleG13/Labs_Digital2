

String opcion = "";

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("/////////MENÚ//////////");
 


 
}

void loop()
{
   Serial.println("\n Elija la opción de su preferencia:");
   Serial.println("1 - Opción 1");
   Serial.println("2 - Opción 2");
   Serial.println("3 - Opción 3");
   opcion = leerfrase();
   if(opcion == 1){
    
   }
   Serial.print("Usted escogio la opción: ");
   Serial.println(opcion);
 
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
