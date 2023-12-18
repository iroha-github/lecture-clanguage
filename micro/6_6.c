int MOTOR = 3; // LED はピン3 に接続
int VR = 0; // 可変抵抗器（ボリューム）はピンA0 に接続
int in_val = 0; // 入力したアナログ値を入れておく変数
int out_val = 0; // 出力用のアナログ値を入れておく変数
void setup() {
pinMode(MOTOR, OUTPUT);
}
void loop() {
in_val = analogRead(VR);
// 可変抵抗器（ボリューム）の信号を変数val に入力
// 入力したアナログ値の範囲は0 から1023 である．
out_val = in_val / 4;
// PWM で出力する値の範囲は0 から255 なので

//入力したアナログ値を1/4 しておく．
analogWrite(MOTOR, out_val);
// 準備したアナログ値を出力する
}