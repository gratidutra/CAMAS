// PINOUT CS EM 4 ,sd card (sck 13,miso12,mosi11cs4) A1 SENSOR AMINIA SENSOR TEMOPERATURA PINO 7
 #include <SD.h>
 #include <DHT.h>; //INCLUSÃO DE BIBLIOTECA 
 #include <Wire.h> 
 const int intervalo =180000;
#define DHTPIN 7 //PINO DIGITAL UTILIZADO PELO DHT22
#define DHTTYPE DHT22 //DEFINE O MODELO DO SENSOR (DHT22 / AM2302)
int kj;  
int jk;  
int xx; 
int yy;
DHT dht(DHTPIN, DHTTYPE); 
int temp=0; 
 int w =A1;
int i; 
int h =13;
const int CS = 4;  


void setup()
{ 
  pinMode(w,INPUT);
  Serial.begin(9600);
  pinMode(h,OUTPUT);
  if (!SD.begin(CS)) 
  {
    
    return;
  }

}

void loop() 
{ 
  dht.begin();
  


  while(i<480 ){// frequencia de repetição
    File dataFile = SD.open("LEPAV.csv", FILE_WRITE);
 kj =(dht.readHumidity()); 
jk =(dht.readTemperature()); 
xx= analogRead(w);//  y =valor lido convertido para 0 a 5v
yy =map(xx,0,1024,0,300);

    if (dataFile) 
    {   
     
    dataFile.print("Humidade ");  
      dataFile.print("; ");  
      dataFile.print(kj);  
      dataFile.print("; "); 
      dataFile.print("Temperatura = ");  
      dataFile.print("; ");
      dataFile.print(jk);  
       dataFile.print("; ");
      dataFile.print(" Celsius  ");  
       dataFile.print("; "); 
       dataFile.print(" PPM  gás  ");  
       dataFile.print("; "); 
       dataFile.print(yy);  
       dataFile.print("; ");
      dataFile.println(" ");
      dataFile.close();
      delay(intervalo); //tempo de leitura em millis
    //  delay(100); 
    }
     i++;}
    digitalWrite(13,HIGH);
  } 
