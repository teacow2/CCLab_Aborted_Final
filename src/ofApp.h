#pragma once

#include "ofMain.h"
#include "C:\Users\errat\Dropbox\MiscellanyNick\Programming\of_v0.8.4_win_cb_release\of_v0.8.4_win_cb_release\include\Mothership.h"
#include "C:\Users\errat\Dropbox\MiscellanyNick\Programming\of_v0.8.4_win_cb_release\of_v0.8.4_win_cb_release\include\Ships.h"
#include "..\..\..\include\Shot.h"
#include "..\..\..\include\Target.h"

#include <string>
#include <vector>

using namespace std;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Mothership player = new Mothership();
        Mothership hiveShip = new Mothership();

        vector<Ships> playerShip;
        vector<Ships> enemyShip;
        vector<Shot> playerShots;
        vector<Shot> enShots;
        vector<Target> shipType;

		int numEn;
        int resources;
        int shotAura;
        string[] purchaseShips;
        int[] shipCosts;



}
