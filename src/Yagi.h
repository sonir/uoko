//
//  Yagi.h
//  yagiSys
//
//  Created by sonir on 6/22/15.
//
//

#ifndef __yagiSys__Yagi__
#define __yagiSys__Yagi__

#define SC_WIDTH 1280
#define SC_HEIGHT 1080
#define SC_MARGIN_WIDTH 100
#define SC_MARGIN_HEIGHT 70
#define SQUARE_SIZE 10.0f

#define CIRCLE_SIZE 120
#define CIRCLE_NUM 8
#define CIRCLE_MARGIN CIRCLE_SIZE*2.5f
#define CIRCLE_MARGIN_TOP CIRCLE_SIZE+SC_MARGIN_HEIGHT
#define CIRCLE_COLUMN 4


#include <stdio.h>
#include "slAppManager.h"
#include "slObserver.h"
#include "SeqManager.h"
#include "slAdsr.h"
#include "setup.h"
#include "hnDmxMng.h"
#include "Preset.hpp"



class YagiApp : public slAppManager, slObserver {
    
    public:
        SeqManager sqcr;
        void setup();
        void update();
        void draw();
        void mute();
        void event(event_type tag, void *param); //Invoke from slNotice
        command_e now_phase = VOID;

    
    private:
        void drawCircles();
        slNotice *notice;
        color_e sc_color;
        hnDmxMng output;
        Preset preset;
    
};

#endif// /* defined(__yagiSys__Yagi__) */
