////  LevelScene.h//  dianliwangguomanyouji////  Created by szsycx on 3/16/15.////#ifndef __dianliwangguomanyouji__LevelScene__#define __dianliwangguomanyouji__LevelScene__#include "cocos2d.h"#include "ui/CocosGUI.h"using namespace cocos2d::ui;#include "SimpleAudioEngine.h"using namespace CocosDenshion;USING_NS_CC;class LevelScene :public Layer{public:    virtual bool init();    static Scene* createScene();    CREATE_FUNC(LevelScene);private:    Button*back;    int currentSeason;    static constexpr int LEVEL_NUMBER = 12;    static constexpr int BACK_TAG = 0;    static constexpr int SHOP_TAG = -1;    static constexpr int ITEM_BG = 100;    //    Sprite * itemInfoBg1;//    Sprite * itemInfoBg2;//    Sprite * itemInfoBg3;    Button * itemInfo1;    Button * itemInfo2;    Button * itemInfo3;    Button * itemInfo4;};#endif /* defined(__dianliwangguomanyouji__LevelScene__) */