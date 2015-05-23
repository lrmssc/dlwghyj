////  MenuScene.cpp//  dianliwangguomanyouji////  Created by szsycx on 3/15/15.////#include "MenuScene.h"#include "SimpleAudioEngine.h"#include "CastleScene.h"#include <string>using namespace std;using namespace CocosDenshion;//using namespace cocos2d::extension;Scene * MenuScene::createScene(){    Scene * scene = Scene::create();    Layer * layer = MenuScene::create();    scene->addChild(layer);    return scene;}bool MenuScene::init(){    if(!Layer::init()){        return false;    }        int  beanNumber = UserDefault::getInstance()->getIntegerForKey("bean", 100);    int  item1Number = UserDefault::getInstance()->getIntegerForKey("item1", 10);    int  item2Number = UserDefault::getInstance()->getIntegerForKey("item2", 5);    int  item3Number = UserDefault::getInstance()->getIntegerForKey("item3", 2);    int  item4Number = UserDefault::getInstance()->getIntegerForKey("item4",1);    isPlayMusic = UserDefault::getInstance()->getBoolForKey("music", true);    item3Number=200;    if(isPlayMusic){         CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("xuqu.mp3");        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xuqu.mp3", true);    }    UserDefault::getInstance()->setIntegerForKey("bean", beanNumber);    UserDefault::getInstance()->setIntegerForKey("item1", item1Number);    UserDefault::getInstance()->setIntegerForKey("item2", item2Number);    UserDefault::getInstance()->setIntegerForKey("item3", item3Number);    UserDefault::getInstance()->setIntegerForKey("item4", item4Number);    UserDefault::getInstance()->flush();                   Size visibleSize = Director::getInstance()->getVisibleSize();        isFirstEnterGame = UserDefault::getInstance()->getBoolForKey("first", true);//    if(a==""){//        isFirstEnterGame = true;//    }    isMale = UserDefault::getInstance()->getBoolForKey("male", true);//    log("isFirst %i",isFirstEnterGame);    auto bg = Sprite::create("menu/bg.jpg");    bg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));    addChild(bg);        bg2 = Sprite::create("menu/bg2.jpg");    bg2->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));    bg2->setVisible(false);    addChild(bg2);        title = Sprite::create("menu/title.png");    title->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height*7.0/10.0));    addChild(title);        boy = Button::create("menu/c1.png");    boy->setPosition(Vec2(visibleSize.width/4.0,visibleSize.height/2.0));    boy->setVisible(false);    boy->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            boy->setColor(Color3B(255,255,255));            girl->setColor(Color3B(100, 100, 100));            nameInput->setVisible(true);            inputBg->setVisible(true); ok->setVisible(true);            isMale= true;        }    });    addChild(boy);        girl = Button::create("menu/c2.png");    girl->setPosition(Vec2(visibleSize.width*3.0/4.0,visibleSize.height/2.0));    girl->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            boy->setColor(Color3B(100, 100, 100));            girl->setColor(Color3B(255,255,255));            isMale=false; ok->setVisible(true);            nameInput->setVisible(true);            inputBg->setVisible(true);        }    });    girl->setVisible(false);    addChild(girl);        float diffUp = -visibleSize.height/4.0;        inputBg = Sprite::create("menu/inputbg.png");    inputBg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0-diffUp));    inputBg->setVisible(false);    addChild(inputBg);        nameBg = ImageView::create("menu/namebg.png");    nameBg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0-nameBg->getContentSize().height*4.0/10.0-diffUp));    nameBg->setVisible(false);    addChild(nameBg);            nameInput = TextField::create("小明","fonts/zhongwen.ttf",48);    log("namaaaaadsfasdfasfsadfsadfsafdsafsdafse=%s",nameInput->getString().c_str());    nameInput->setPosition(Vec2(visibleSize.width*4.8/10.0,visibleSize.height*45.0/100.0-diffUp));    nameInput->setVisible(false);    nameInput->setMaxLength(5);    nameInput->setMaxLengthEnabled(true);    nameInput->setColor(Color3B(0,255,0));    nameInput->addEventListener([&](Ref* pSender ,TextField::EventType type){            if(type== TextField::EventType::DETACH_WITH_IME){            int length = nameInput->getStringLength();                log("输入 1 length = %d , name = %s",length ,nameInput->getString().c_str());                            if(length>5 ||length==0){                    nameInput->setText("不能超过5个汉字");                }else{                    log("savename = %d , name = %s",length ,nameInput->getString().c_str());                    UserDefault::getInstance()->setStringForKey("name", nameInput->getString().c_str());                    nameInput->setText(nameInput->getString());                    UserDefault::getInstance()->flush();                    nameInput->setTouchEnabled(false);                    inputBg->setVisible(false);                    nameBg->setVisible(true);                }        }else{            log("输入 2 name = %s" ,nameInput->getString().c_str());        }    });    addChild(nameInput);        ok = Button::create("menu/ok.png");    ok->setVisible(false);    ok->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height*2.0/10.0));    ok->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            UserDefault::getInstance()->setBoolForKey("first",false);            isFirstEnterGame = false;            UserDefault::getInstance()->setBoolForKey("male",isMale);            UserDefault::getInstance()->flush();            Director::getInstance()->replaceScene(CastleScene::createScene());        }    });    addChild(ok);        startGame = Button::create("menu/begin.png");    startGame->setPosition(Vec2(visibleSize.width/2,visibleSize.height*2.0/10.0));    startGame->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type== Widget::TouchEventType::ENDED){//            log("ENDED %i",isFirstEnterGame);                        if(isFirstEnterGame){                boy->setVisible(true);                girl->setVisible(true);                bg2->setVisible(true);//                inputBg->setVisible(true);                title->setVisible(false);                               startGame->setVisible(false);//                closeGame->setVisible(false);            }else{                UserDefault::getInstance()->flush();                auto transitions = TransitionPageTurn::create(0.4f, CastleScene::createScene(),false);                Director::getInstance()->replaceScene(transitions);            }        }    });    addChild(startGame);    //    sound = Button::create("menu/sound.png");//    if(!isPlaySound){//        sound->setColor(Color3B(50,50,50));//    }//    sound->setPosition(Vec2(visibleSize.width-sound->getContentSize().width/2.0,visibleSize.height-sound->getContentSize().height/2.0-1));//    //    sound->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){//        if(type== Widget::TouchEventType::ENDED){//            //            log("ENDED %i",isFirstEnterGame);//            //            isPlaySound=!isPlaySound;//            //            //            if(isPlaySound){//                sound->setColor(Color3B(255,255,255));//            }else{//                sound->setColor(Color3B(50,50,50));//            }//            UserDefault::getInstance()->setBoolForKey("sound", isPlaySound);//                  }//    });////    addChild(sound);        music = Button::create("menu/music.png");    umusic = Button::create("menu/umusic.png");        if(!isPlayMusic){        music->setVisible(false);    }    music->setPosition(Vec2(visibleSize.width-music->getContentSize().width/2.0,visibleSize.height-music->getContentSize().height/2.0-1));    music->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type== Widget::TouchEventType::BEGAN){            log("0isPlayMusic %i  %i",isPlayMusic,(isPlayMusic==false));                                    log("2isPlayMusic %i",isPlayMusic);                CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();                isPlayMusic = false;                log("222isPlayMusic %i  %i",isPlayMusic,(isPlayMusic==false));            UserDefault::getInstance()->setBoolForKey("music", isPlayMusic);                    }    });    addChild(music);            if(isPlayMusic){        umusic->setVisible(false);    }    umusic->setPosition(Vec2(visibleSize.width-music->getContentSize().width/2.0,visibleSize.height-music->getContentSize().height/2.0-1));    umusic->addTouchEventListener([&](Ref* pSender,Widget::TouchEventType type){        if(type== Widget::TouchEventType::BEGAN){                                       log("1isPlayMusic %i",isPlayMusic);            CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("xuqu.mp3");                CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xuqu.mp3", true);                isPlayMusic = true;                log("11isPlayMusic %i",isPlayMusic);                                        UserDefault::getInstance()->setBoolForKey("music", true);                    }    });    addChild(umusic);                    scheduleUpdate();    return true;}void MenuScene::update(float dt){    if(isPlayMusic){                   umusic->setVisible(false);        music->setVisible(true);    }else{           umusic->setVisible(true);        music->setVisible(false);    }}