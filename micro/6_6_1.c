int MOTOR = 3; // LED はピン3 に接続
int VR = 0; // 可変抵抗器（ボリューム）はピンA0 に接続
int in_val = 0; // 入力したアナログ値を入れておく変数
int out_val = 0; // 出力用のアナログ値を入れておく変数
int var = 0; // 計算結果を入れておく変数

void setup() {
    pinMode(MOTOR, OUTPUT);
}

void loop() {
    in_val = analogRead(VR);
    if(in_val <512) {
        var = in_val / 2;
    } else {
        var = (1023 - in_val) / 2;
    }
    analogWrite(MOTOR, var);
}d