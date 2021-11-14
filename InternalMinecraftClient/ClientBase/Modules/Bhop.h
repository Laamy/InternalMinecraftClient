#pragma once

class Bhop : public Module {
public:
    Bhop(std::string cat) : Module(cat, "Bhop", 0x07) {};
	  ClientInstance* ci;
    int jumpDelay = 0;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		this->ci = ci;
	};


    void OnGameTick(Actor* lp)
    {
        if (lp == nullptr) return;

        if (!lp->onGround2)
        {
            Vector3 newVel = lp->Velocity;

            auto cy = (lp->bodyRots()->y + 89.9) * ((float)PI / 180);

            if (keymap['W'] || keymap['A'] || keymap['S'] || keymap['D'])
            {
                if (keymap['A'])
                    cy += 55;
                if (keymap['S'])
                    cy += 110;
                if (keymap['D'])
                    cy -= 55;

                int speed = 7;

                newVel.z = (float)sin(cy) * (speed / 2);
                newVel.x = (float)cos(cy) * (speed / 2);

                lp->Velocity = newVel;

                if (jumpDelay != 0)
                    jumpDelay = 0;
            }
        }
        else
        {
            if (keymap['W'] || keymap['A'] || keymap['S'] || keymap['D'])
            {
                jumpDelay++;
                if (jumpDelay == 2)
                    lp->Velocity.y = 0.4;
            }
        }
    }//it works really bad, but i didnt have lots of time to make it work good, prob gonna make it better another time
};
