int LED = 9; // LED はピン9 に接続
int VR = 0; // 可変抵抗器（ボリューム）はピンA0 に接続
int in_val = 0; // 入力したアナログ値を入れておく変数
int out_val = 0; // 出力用のアナログ値を入れておく変数
void setup() {
pinMode(LED, OUTPUT);
}

void loop() {
in_val = analogRead(VR);

if(in_val < 613) {
  out_val = 0;
} else {
  out_val = in_val / 4;
}
// 準備したアナログ値を出力する
    analogWrite(LED, out_val);
}