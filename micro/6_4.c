/*6_4.c
LED の明るさをPWM を用いて2 段階で変更するプログラムを作成する．プログラムを起動す
るとLED が薄暗く点灯し，押しボタンスイッチを押すと明るくなるようにする．
Arduino はPWM 回路が内蔵されているので，プログラムでは関数analogWrite(pin, value)
を使ってそのPWM 回路を使用する．Arduino ではピン3，5，6，9，10，11 でこの機能が使え
る．PWM の基準周波数はピン5 と6 は約980Hz で，それ以外は約490Hz となっている．関数
analogWrite() を使用する前にpinMode() を呼び出してピンを出力に設定する必要はない．関数
analogWrite(pin, value) のパラメータpin は出力に使うピンの番号，value はデューティ比（0 か
ら255）を表す．value に0 を指定すると0V の電圧が出力され，255 を指定すると5V が出力さ
れる．すなわち出力電圧の最大値は電源電圧と同じである．プログラムは次のようになる．プログ
ラム中の変数BRIGHT と変数DARK の値を変更して，明るさの違いを確かめること．
*/

int LED = 9; // LED
int SW = 13; // スイッチ
int BRIGHT = 255; // 明るい
int DARK = 100; // 暗い
void setup()
{
    pinMode(SW, INPUT);
}
void loop()
{
    if(digitalRead(SW) == HIGH) {
        analogWrite(LED, DARK);
    } else {
        analogWrite(LED, BRIGHT);
    }
}