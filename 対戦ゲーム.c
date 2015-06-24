#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//「対戦ゲーム」
/*
 ---------仕様----------
 プレイヤー名 => char player配列
 自分のHP => int hp
 敵のHP => int enemy_hp
 選択肢 => char yesno_char
 選択肢2 => int yesno_int
 ダメージ　=> int damage
 敵からのダメージ => int enemy_damage
 選択肢は逃げるor攻撃する
 */
//変数の定義をグローバル変数で行う
char player[255];//プレイヤー名
int hp = 100;//自分のHP
int enemy_hp = 500;//敵のHP
char yesno_char = 'n';//はいorいいえ
int yesno_int = 0;//攻撃するか否か
int damage = 100;//自分が与えるダメージ
int enemy_damage = 100;//敵が与えてくるダメージ

//モンスターとの対戦
void monster(void){
    printf("▼%sはどうする・・・・\n1戦う,2逃げる\n",player);
    scanf("%d",& yesno_int);
}

int main(void) {
    
    
    //プレイヤー設定
    while(yesno_char == 'n'){
        //プレイヤー名の入力
        printf("ようこそ！！\nあなたは今日から冒険家です！\nプレイヤー名を入力してください！！\n");
        rewind(stdin);
        
        //プレイヤー名を入力させる
        scanf("%s",player);
    
        //プレイヤー名の確認
        printf("\n\n%sさんでよろしいですか？？\nOKなら「y」をダメなら「n」を入力してください\n",player);
        rewind(stdin);
        scanf("%c",& yesno_char);
    }
    
    printf("\n%sさん、今日からあなたも冒険家の一人です！\n早速これから出てくるモンスターと戦ってください！\n\n\n出てきました！敵モンスターのクマモンです！！\n",player);
    
    //モンスターと遭遇
    while(enemy_hp >= 0){
        monster();
        switch (yesno_int) {
            case 1:
                printf("%sは攻撃した！\n",player);
                printf("敵のHPは%dだ！",enemy_hp);
                enemy_hp -= damage;
                break;
            case 2:
                enemy_hp = -1;
                break;
            default:
                printf("入力された値が間違えています\n");
                monster();
                break;
        }
    }
    if(enemy_hp == -100){
        printf("\n敵を倒したぞ！！！\n");
    }else if(enemy_hp == -1){
        printf("%sは逃げた,,,,,！！\n",player);
    }
    return 0;
}
