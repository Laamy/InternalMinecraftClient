#pragma once

bool RightBar = false; // set this to true for a cool Right bar

class ArrayList : public Module {
public:
    ArrayList(std::string cat) : Module(cat, "ArrayList", "Display list of modules that are enabled", 0x07, true) {};

    // Length compare for module
    struct moduleLengthCompare {
        inline bool operator() (const Module* l, const Module* r) {
            return l->vElement->len < r->vElement->len;
        }
    };

    void OnFrameRender(RenderUtils* ctx) override {
        // Sort modules by name length
        std::sort(vMods.begin(), vMods.end(), moduleLengthCompare());
        std::reverse(vMods.begin(), vMods.end());
        // Client values
        float offset = 0.f;
        float fontHeightPadding = 10.f;
        float lastStartPos = 0;
        float modLen = 0;
        Rect lastPos;
        Rect boxPos;
        Rect sideBoxPos;
        Rect RightbarPos;
        _RGB translucentBlack;
        _RGB rainbow;
        // Game values
        Vector2 resolution = ctx->guiData->scaledResolution;
        BitmapFont* font = ctx->font;

           // Colors
           translucentBlack = _RGB(0.f, 0.f, 0.f, 127.5f);
           rainbow = ctx->getRainbow(5.0f, 1.0f, 1.0f, 255.f, 255.f, 255.f, 255.f);
           // Do rainbow wave
           long rainbowIndex = offset * 50;
           rainbow = ctx->getRainbow(5, 1.0f, 1.0f, rainbowIndex, 255.f, 255.f, 255.f, 255.f);


        // Loop through our modules
        for (Module* mod : vMods) {
            // Check if enabled before rendering
            if (!mod->enabled)
                continue;
            // Get length of the string
            if (RightBar)
                modLen = ctx->MeasureText(mod->name, font) + 6;
            else
                modLen = ctx->MeasureText(mod->name, font) + 4;
            mod->vElement->len = modLen;

            // Get position of outer boxes
            float currentYOffset = fontHeightPadding * offset;
            boxPos = Rect(resolution.x - modLen, currentYOffset, resolution.x, currentYOffset + fontHeightPadding);
            sideBoxPos = Rect(boxPos.x - 1.f, boxPos.y, boxPos.x, boxPos.w);
            RightbarPos = Rect(resolution.x - 3.f, currentYOffset, resolution.x, currentYOffset + fontHeightPadding);

            // Render box behind text
            ctx->Draw(boxPos, translucentBlack);
            if (!RightBar) {
                // Render side box
                ctx->Draw(sideBoxPos, rainbow);

                // Underline
                if (lastStartPos != 0)
                    ctx->Draw(Rect(lastStartPos - 1.f, boxPos.y, boxPos.x, boxPos.y + 1.0f), rainbow);
                lastStartPos = boxPos.x;
                lastPos = boxPos;
            }
            else {
                // Render Right Bar
                ctx->Draw(RightbarPos, rainbow);
            }

            // Render text
            ctx->DrawString(Vector2(boxPos.x + 2, boxPos.y), rainbow, TextHolder(mod->name), font);

            // Increase module offset
            offset += 1.f;
        }
        // Underline last arraylist mod
        if(!RightBar)
        ctx->Draw(Rect(lastPos.x - 1.f, lastPos.w, lastPos.z, lastPos.w + 1.f), rainbow);
    }
};