/* COUFFIN Manon 
   JOBERT Pauline 
      1A SRI        */

void setup() {
  
 //on definit la frequence de transmission a 19200 bauds
 Serial.begin(19200);
 //on définit le port 2 analogique en sortie, sur lequel on branche la LED
 pinMode(2, OUTPUT);
  

}

void loop() {
  
  //on recupère la valeure lue et convertie de A0 qui est compris entre 0 et 1023
  float valeur=analogRead(A0);
  //on convertie la valeur en degres avec un produit en croix, sachant que pour 5V on obtient 1023 et que pour 10mV, on a 1 degre
  Serial.println(valeur*330.0/1023.0);
  //on eclaire la LED (qui peut prendre une valeur entre 0 et 255), on divise donc le resultat par 4 car le resultat max est 1023 et 1023/4 = 255
  analogWrite(2, valeur/4);
  delay(1000);
  
  //faire clignoter la LED
  analogWrite(2, 255);
  delay(500);
  analogWrite(2,0);
  delay(500);
  

}
