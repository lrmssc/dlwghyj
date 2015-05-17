////  MagicGame.h//  dianliwangguomanyouji////  Created by szsycx on 3/18/15.////#ifndef __dianliwangguomanyouji__MagicGame__#define __dianliwangguomanyouji__MagicGame__#include "cocos2d.h"#include <vector>#include "ui/CocosGUI.h"#include "SimpleAudioEngine.h"USING_NS_CC;using namespace CocosDenshion;using namespace cocos2d::ui;using namespace std;class MagicGame :public Layer{public:    static Scene * createScene();    virtual bool init();    CREATE_FUNC(MagicGame);    void swapTwoBoxPosition(Sprite* sprite1,Sprite* sprite2,Sprite* sprite3,Sprite* sprite4);    void swap();private:    vector<Sprite*> items;    vector<Sprite*> box;    vector<Vec2> positions;    static constexpr int SWAP_NUMBER = 5;    int swapNumber =0;    void update(float dt);    bool over;    int touchIndex;    Size visibleSize;    int currentSeason;    int maxLevel ;    Sprite * textBg;    Text * text;    string name;    int i  =0;};#endif /* defined(__dianliwangguomanyouji__MagicGame__) */