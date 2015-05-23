////  MagicGame.cpp//  dianliwangguomanyouji////  Created by szsycx on 3/18/15.////#include "MagicGame.h"#include "LevelScene.h"Scene * MagicGame::createScene(){    Scene * scene = Scene::create();    Layer * layer = MagicGame::create();    scene->addChild(layer);    return scene;}bool MagicGame::init(){    if(!Layer::init()){        return false;    }    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();    currentSeason = UserDefault::getInstance()->getIntegerForKey("current_season", 1);    int currentLevel =UserDefault::getInstance()->getIntegerForKey("current_level", 1);    trueMaxLevel =UserDefault::getInstance()->getIntegerForKey(StringUtils::format("true_max_level%d",currentSeason).c_str(), 1);        visibleSize= Director::getInstance()->getVisibleSize();                m_EventListener = EventListenerTouchOneByOne::create();    m_EventListener->onTouchBegan= [](Touch* touch,Event * event){        if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){            return true;        }        return false;    };    m_EventListener->onTouchMoved= [](Touch* touch,Event * event){        if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){                    }            };    m_EventListener->onTouchEnded= [&](Touch* touch,Event * event){        if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){            talk->setVisible(false);            talkbg->setVisible(false);            isStart = true;        }            };        talkbg = Sprite::create("game/talkbg.png");    talkbg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));               switch(currentSeason){        case 1:           {               if(currentLevel==6){                   talk = Text::create("菜瓜：原来是高手啊！失敬失敬~\n先放松一下！选一个宝贝吧！", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("菜瓜：还有一步就可以通过魔力\n大门了！选一个宝贝吧！加油~", "fonts/zhongwen.ttf", 40);               }           }            break;        case 2:           {               if(currentLevel==6){                   talk = Text::create("天天：你能答对这么多题已经很\n不错了！休息一下，该选宝贝了！", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("天天：你居然还在前进！下一步很\n少有人通过了，选你的宝贝吧！", "fonts/zhongwen.ttf", 40);               }           }            break;           case 3:  {               if(currentLevel==6){                   talk = Text::create("白雪：哇！好崇拜你哦~选我送给你的礼物吧~", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("白雪：你是我见过最棒的！还有一步就通过\n天使城了，带上我送到你的礼物吧~", "fonts/zhongwen.ttf", 40);               }           }            break;           case 4:  {               if(currentLevel==6){                   talk = Text::create("怪兽瞳：我已经饿了太久了，不在乎再多等\n你一会儿~", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("怪兽瞳：你真地想从这里出去吗？那就再靠\n近我一点点……让我看清你……", "fonts/zhongwen.ttf", 40);               }           }            break;           case 5:  {               if(currentLevel==6){                   talk = Text::create("E博士：嗯，有点实力，难怪能走到这里，\n选你想要的礼物吧~", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("E博士：你下面要挑战的，是现实城堡中\n的最后一关，带上我送你的礼物吧，\n祝你好运！", "fonts/zhongwen.ttf", 40);               }           }            break;           case 6:  {               if(currentLevel==6){                   talk = Text::create("光明女神：在人类中，你足够优秀，\n选一件你喜欢的装备吧~", "fonts/zhongwen.ttf", 40);               }else{                   talk = Text::create("光明女神：你已经掌握了这星球上所有\n电力与能源的知识，还有一步，你将\n回到这一切开始的地方~", "fonts/zhongwen.ttf", 40);               }           }            break;                          default:           {                                  talk = Text::create("菜瓜：原来是高手啊！失敬失敬~\n先放松一下！选一个宝贝吧！", "fonts/zhongwen.ttf", 40);                          }               break;    }    talk->setColor(Color3B(93,44,24));    _eventDispatcher->addEventListenerWithSceneGraphPriority(m_EventListener, talkbg);    talk->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height*5.6/10.0));        positions.push_back(Vec2(visibleSize.width*3.65/10.0,visibleSize.height*7.2/10.0));    positions.push_back(Vec2(visibleSize.width*6.35/10.0,visibleSize.height*7.2/10.0));    positions.push_back(Vec2(visibleSize.width*3.65/10.0,visibleSize.height*3.5/10.0));    positions.push_back(Vec2(visibleSize.width*6.35/10.0,visibleSize.height*3.5/10.0));                auto bg = Sprite::create(StringUtils::format("game/qbg%d.jpg",currentSeason));    bg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));    addChild(bg);        maxLevel = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("max_level%d",currentSeason).c_str(), 1);        auto dbg = Sprite::create("game/dbg.png");    dbg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));    addChild(dbg);    int j = random(1, 4);    int cc= 0;    for (int i =0 ; i<5; i++) {        if(i==j){            continue;        }               auto sprite = Sprite::create(StringUtils::format("game/box%d.png",(i+1)).c_str());        sprite->setPosition(positions[cc]);        itemIndex.insert(i+1, sprite);        sprite->setTag(0);        items.push_back(sprite);        auto sprite2 = Sprite::create("game/box6.png");        sprite2->setVisible(false);        sprite2->setTag(i+1);        sprite2->setPosition(positions[cc++]);        box.push_back(sprite2);        addChild(sprite2);        addChild(sprite);    }    swapNumber =0 ;            textBg = Sprite::create("bgtiao.png");    textBg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height*7.5/10.0));    textBg->setVisible(false);    addChild(textBg);    name  =UserDefault::getInstance()->getStringForKey("name", "王小明");    text = Text::create(StringUtils::format("恭喜%s获得奖励",name.c_str()), "", 52);    text->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height*7.5/10.0));    text->setColor(Color3B(93,44,24));    text->setVisible(false);    addChild(text);    scheduleUpdate();            auto listener = EventListenerTouchOneByOne::create();    listener->onTouchBegan= [&](Touch* touch,Event * event){        if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){            return true;        }        return false;    };    listener->onTouchMoved= [](Touch* touch,Event * event){        if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){                    }            };    listener->onTouchEnded= [&](Touch* touch,Event * event){        if(over && i>200){        Director::getInstance()->replaceScene(LevelScene::createScene());            bool isMusicPlay = UserDefault::getInstance()->getBoolForKey("music", true);            if(isMusicPlay){                CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("xuqu.mp3");                CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xuqu.mp3", true);            }        }    };    i = 0;       _eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(),this);        bool isMusicPlay = UserDefault::getInstance()->getBoolForKey("music", true);    if(isMusicPlay){        CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("magic.mp3");        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("magic.mp3", true);    }            addChild(talkbg);    addChild(talk);        player = Sprite::create(StringUtils::format("game/b%da.png",currentSeason).c_str());    player->setPosition(Vec2(player->getContentSize().width/2.0,player->getContentSize().height/2.0));    addChild(player);        bool isMale = UserDefault::getInstance()->getBoolForKey("male",true);    if(isMale){        hero= Sprite::create("game/userboya.png");            }else{        hero= Sprite::create("game/usergirla.png");    }    hero->setPosition(Vec2(visibleSize.width-hero->getContentSize().width/2.0,hero->getContentSize().height/2.0));    addChild(hero);    return true;}void MagicGame::update(float dt){    if(!isStart){        return ;    }    if(swapNumber<SWAP_NUMBER&&Director::getInstance()->getActionManager()->getNumberOfRunningActionsInTarget(box[0])==0){        if(swapNumber==1){            for(Sprite * i :items){                i->setVisible(false);            }            for(Sprite * i:box){                i->setVisible(true);            }        }        swapNumber++;                swap();    }else{        auto listener = EventListenerTouchOneByOne::create();        listener->onTouchBegan= [&](Touch* touch,Event * event){            if(swapNumber==SWAP_NUMBER&&event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){                return true;            }            return false;        };        listener->onTouchMoved= [](Touch* touch,Event * event){            if(event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){                            }                    };        listener->onTouchEnded= [&](Touch* touch,Event * event){            if( event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())){                if(!over){                int tag = event->getCurrentTarget()->getTag();                if(tag>0 && !textBg->isVisible() && !text->isVisible()){                    // // 间 光 一 ❤️ 豆                    switch(tag){                        case 1:                        {                            text->setText(StringUtils::format("恭喜%s获得电之剑",name.c_str()));                            int n = UserDefault::getInstance()->getIntegerForKey("item1");                            UserDefault::getInstance()->setIntegerForKey("item1",n+1);                        }                            break;                        case 2:  {text->setText(StringUtils::format("恭喜%s获得电之光",name.c_str()));                            int n = UserDefault::getInstance()->getIntegerForKey("item2");                            UserDefault::getInstance()->setIntegerForKey("item2",n+1);}break;                        case 3:  {text->setText(StringUtils::format("恭喜%s获得电之翼",name.c_str()));                            int n = UserDefault::getInstance()->getIntegerForKey("item3");                            UserDefault::getInstance()->setIntegerForKey("item3",n+1);                        }break;                        case 4:  {text->setText(StringUtils::format("恭喜%s获得还魂丹",name.c_str()));                            int n = UserDefault::getInstance()->getIntegerForKey("item4");                            UserDefault::getInstance()->setIntegerForKey("item4",n+1);                        }                            break;                        case 5:  {text->setText(StringUtils::format("恭喜%s获得100个电豆",name.c_str()));                            int n = UserDefault::getInstance()->getIntegerForKey("bean");                            UserDefault::getInstance()->setIntegerForKey("bean",n+100);                        }break;                    }                                      itemIndex.at(tag)->setPosition(event->getCurrentTarget()->getPosition());                    itemIndex.at(tag)->setVisible(true);                    auto move = MoveTo::create(0.5, Vec2(visibleSize.width/2.0,visibleSize.height/2.0));                  //  box[itemIndex.at(tag)]->setVisible(false);                    over = true;                                        UserDefault::getInstance()->setBoolForKey(StringUtils::format("magic%d%d",currentSeason,maxLevel).c_str(),true);                                                      UserDefault::getInstance()->setIntegerForKey(StringUtils::format("max_level%d",currentSeason).c_str(),++maxLevel);                                        UserDefault::getInstance()->setIntegerForKey(StringUtils::format("true_max_level%d",currentSeason).c_str(), ++trueMaxLevel);                    UserDefault::getInstance()->flush();                    textBg->setVisible(true);                    text->setVisible(true);                    event->getCurrentTarget()->setVisible(false);                    itemIndex.at(tag)->runAction( Sequence::create(move,CallFunc::create([&]()                                                                                           {                                                                                                                                                                                              while(i<500){                                                                                                   i++;                                                                                                                  }                                                                                                                                                                                          }),NULL));                }                }else{                                    }            }        };        for(int i = 0 ; i < 4 ; i ++){            _eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(),box[i]);            _eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(),items[i]);        }    }}void MagicGame::swapTwoBoxPosition(Sprite* sprite1,Sprite*sprite2,Sprite* sprite3,Sprite*sprite4){    Vec2 position1 = sprite1->getPosition();    Vec2 position2 = sprite2->getPosition();    sprite1->runAction(MoveTo::create(0.5, position2));    sprite2->runAction(MoveTo::create(0.5, position1));    Vec2 position3 = sprite3->getPosition();    Vec2 position4 = sprite4->getPosition();    sprite3->runAction(MoveTo::create(0.5, position4));    sprite4->runAction(MoveTo::create(0.5, position3));}void MagicGame::swap(){    int first = random(0, 12)%box.size();    int second = (first+1)%box.size();    int third = (second+1)%box.size();    int forth = (third+1)%box.size();    swapTwoBoxPosition(box[first],box[second],box[third],box[forth]);}