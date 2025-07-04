#pragma once

#include <libultraship.h>
#include <vector>
#include "Object.h"

#include "World.h"

extern "C" {
#include "macros.h"
#include "main.h"
#include "vehicles.h"
#include "waypoints.h"
#include "common_structs.h"
#include "objects.h"
#include "camera.h"
#include "some_data.h"
}

class OTrashBin : public OObject {
public:

    enum Behaviour {
        STATIC, // The lid stays shut
        MUNCHING // The lid opens/closes in a scary munching manner
    };
    explicit OTrashBin(const FVector& pos, const IRotator& rotation, f32 scale, OTrashBin::Behaviour bhv);

    virtual void Tick() override;
    virtual void Draw(s32 cameraId) override;
    void func_8007E00C(s32 objectIndex);
    void init_bb_trash_bin(s32);

private:
    static Gfx BinMod[];
    static Vtx BinVtx[];
    static Vtx BinVtx2[];

    Behaviour _bhv;
    FVector _pos;
    IRotator _rot;
    float _scale;
    size_t _idx;
    bool _drawBin = false;
};
