
#include <DHT.h>; //INCLUSÃO DE BIBLIOTECA
 
#define DHTPIN 7 //PINO DIGITAL UTILIZADO PELO DHT22
#define DHTTYPE DHT22 //DEFINE O MODELO DO SENSOR (DHT22 / AM2302)
 
DHT dht(DHTPIN, DHTTYPE); //PASSA OS PARÂMETROS PARA A FUNÇÃO
  int amonia=A3; 
 int am;  
 int k = 5000;
 float amoniaconvert; 
 int y=300000;
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  dht.begin(); //INICIALIZA A FUNÇÃO 
   pinMode(amonia,INPUT);   
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}
void loop(){ 
    am = analogRead(amonia); 
       amoniaconvert = map(am,0,1023,0, 290);
    Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(dht.readHumidity()); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
    Serial.print("%"); //IMPRIME O TEXTO NA SERIAL 
    Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(dht.readTemperature(), 2); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
    Serial.print("*C"); //IMPRIME O TEXTO NA SERIAL 

 Serial.print(" amonia PPM convertida "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(amoniaconvert,2);  
     Serial.print(" amonia PPM  sem conversao ");
   Serial.print(am);
     Serial.println("");
    delay(60000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR 
    
}
