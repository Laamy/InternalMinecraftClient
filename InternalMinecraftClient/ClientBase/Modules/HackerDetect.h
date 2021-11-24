#pragma once

class HackerDetect : public Module {
public:
	HackerDetect(std::string cat) : Module(cat, "HackerDetect", "Detect hackers", 0x07) {};
  Vector3 savedPos;
  int ticks = 0;

	void OnGameTick(Actor* lp) override {
		auto localPlayer = clientInst->getCPlayer();
    for (auto ent : clientInst->getEntityList()) {
      auto player = ent;
      
      
      if(ticks < 10){
        ticks++;
        savedPos = ent->Position.lower;
      
      }else { 
        if(ticks > 200){
          if(ent->Position.lower.y > savedPos.y + 30){
         // hooks.debug("HackerDetect", "Flight/highjump");
         //debug msg
            ticks = 0;
          }
        }
      }
    }
	}
};
