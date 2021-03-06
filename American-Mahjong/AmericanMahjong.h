#ifndef AMERICAN_MAHJONG_H
#define AMERICAN_MAHJONG_H

#include "Tiles.h"
#include "Dice.h"
#include "Wind.h"
#include <stdio.h>
#include <iostream> // cout
#include <iomanip> // setw
#include <ctime> // time
#include <vector> // vector
#include <string>
#include <algorithm> // sort

using namespace std;

class AmericanMahjong
{
    const int NUMTILE = 152; //　全体の牌の数
    int tiles_left; // 山に残った牌の数. 牌が配られる度にtiles_left--され,0になるとゲーム終了
    string discardType; // 前のプレイヤーが捨てた牌
    vector<Tiles*> yama;// 山の牌を格納するベクター
    vector<Tiles*> tehuda1; // 親用 tehuda1のみ開始時に14個牌を格納する
    vector<Tiles*> tehuda2; // tehuda2~4は子用で開始時に13個牌を格納する
    vector<Tiles*> tehuda3;
    vector<Tiles*> tehuda4;
    vector<Tiles*> myCards; // 手札の牌を格納したベクター用ポインタ
    vector<Tiles*> cp1Cards; // CP1手札用ポインタ
    vector<Tiles*> cp2Cards; // CP2手札用ポインタ
    vector<Tiles*> cp3Cards; // CP3手札用ポインタ
    vector<Tiles*> tmpCards; // ソート用の一時的なベクター
    vector<Tiles*> myPons; // 手札の牌を格納したベクター用ポインタ
    vector<Tiles*> cp1Pons; // CP1手札用ポインタ
    vector<Tiles*> cp2Pons; // CP2手札用ポインタ
    vector<Tiles*> cp3Pons; // CP3手札用ポインタ
    vector<vector<Tiles*>*> cards; // ベクターのベクター
    vector<int> num_each_tiles;
    
public:
    AmericanMahjong(); // コンストラクタ
    ~AmericanMahjong(); // デストラクタ
    
    // メンバ関数の宣言
    void set_all_tile(); // 152個の牌を作成しベクターに入れる
    void shuffle_all_tile(); // 牌をシャッフルする
    void set_individual_tile(int wind_num); // 各プレーヤーの牌をセットする
    void swap_ptrs_index(int index1, int index2); //索引1と索引2のポインタを入れ替える
    void print_my_tile(); // 手札を表示
    void print_tile(Tiles* ptr); // 牌の情報を表示する
    void print_tiles(int player); // 引数のプレイヤー番号を元に手札を表示
    void print_cp1_tile(); // cp1の手札を表示
    void print_cp2_tile(); // cp2の手札を表示
    void print_cp3_tile(); // cp3の手札を表示
    void sort_player_tiles(); // 牌をソート
    void pon(int wind); // ぽん
    bool pon_check(int ponPlayer, char discardType); // ポンが可能かチェック
    void print_introduction(int gameCount, Wind wind); // 今回のサイコロの数字と各プレーヤーの風を表示
    void trade_tiles1(); //　牌を交換する(1回目)
    void trade_tiles2(); //　牌を交換する(2回目)
    void trade_tiles3(); //　牌を交換する(3回目)
    void trade_tiles4(); // 向かい側の人と牌を交換(0~3個まで)
    void trade_tiles5(); // メッシュ交換
    void start_game(Wind wind); // ゲームを実際に開始する
    void get_tile(int i); // 牌を引く
    void discard_tile_CPU(int i); // CPUが牌を捨てる機能
    void discard_tile_player(); // プレイヤーが牌を捨てる機能
    int evaluate_yaku(int i); // 役を評価し牌がそろっていたら点数を返す,揃っていない場合は-1を返す
    int  count_type(int ponPlayer, string type); // 引数のタイプをいくつ所持しているかを返す
    void count_tileType(int x); // 手札にフラワーとジョーカーの牌がいくつあるかカウントする
    /*
    void count_krack_bamboo_dot(int &a, int &b, int &c, int i); // 手札にクラック、バンブー、ドットタイプの牌がいくつあるかカウントする
    void count_dragons(int &a, int &b, int &c); // 手札にドラゴンの牌がいくつあるかカウントする
    void count_winds(int &a, int &b, int &c, int &d); // 手札にウィンドの牌がいくつあるかカウントする
    void count_flower_joker(int &a, int &b); // 手札にフラワーとジョーカーの牌がいくつあるかカウントする
     */
    void get_tehuda_index(int &a, int &b, int &c); // 交換する牌の索引を入手する(牌の交換時に必要な情報)
    void generate_random_three(int &a, int &b, int &c, unsigned int size); // ランダムに異なる3つの数字を生成する
};


#endif