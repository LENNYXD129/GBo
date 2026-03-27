#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

       
        auto children = this->getChildren();
        for (int i = 0; i < children->count(); ++i) {
            auto child = static_cast<CCNode*>(children->objectAtIndex(i));
            

            std::string id = child->getID();
            if (id.find("geode") != std::string::npos) {
                child->setVisible(false);
                child->setScale(0);
                child->setPosition({-1000, -1000});
            }
        }

        return true;
    }
};