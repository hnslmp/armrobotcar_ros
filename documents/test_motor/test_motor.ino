const int kiri_depan0 = 16;
const int kiri_depan1 = 17;
const int kanan_depan0 = 16;
const int kanan_depan1 = 17;
const int kiri_belakang0 = 14;
const int kiri_belakang1 = 15;
const int kanan_belakang0 = 18;
const int kanan_belakang1 = 19;

void setup(){
  pinMode(kiri_depan0,OUTPUT);
  pinMode(kiri_depan1,OUTPUT);
  pinMode(kanan_depan0,OUTPUT);
  pinMode(kanan_depan1,OUTPUT);
  pinMode(kiri_belakang0,OUTPUT);
  pinMode(kiri_belakang1,OUTPUT);
  pinMode(kanan_belakang0,OUTPUT);
  pinMode(kanan_belakang1,OUTPUT);
}

void loop(){
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
}
