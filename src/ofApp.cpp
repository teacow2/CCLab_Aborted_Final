#include "ofApp.h"
#include "C:\Users\errat\Dropbox\MiscellanyNick\Programming\of_v0.8.4_win_cb_release\of_v0.8.4_win_cb_release\include\Mothership.h"
#include "C:\Users\errat\Dropbox\MiscellanyNick\Programming\of_v0.8.4_win_cb_release\of_v0.8.4_win_cb_release\include\Ships.h"
#include "..\..\..\include\Shot.h"
#include "..\..\..\include\Target.h"
#include <string>
#include <vector>

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
        numEn = 3;
        resources = 2000;
        shotAura = 3;
        purchaseShips  = {"cruiser", "drone", "jet"};
        shipCosts = {50, 100, 200};

         for (int i = 0; i < numEn; i++) {
          ofVec2f tempVec = new ofVec2f();
          tempVec.x = random(25, (width-25));
          tempVec.y = random(100, 120);
          int ranType = int(random(1,3));
          // switch(ranType) {} look up switch
          string tempType = "cruiser";
          enemyShip.push_back(new Ships(tempVec,tempType,"enemy"));
         }

}

//--------------------------------------------------------------
void ofApp::update(){

    // getInterpolated(destination, percentage)
    // draw resource panel
    ofSetColor(78,174, 187);
    ofFill();
    ofRectangle(0, 0, width, 75);
    ofSetColor(255);
    textSize(35);
    text("Resources: " + resources, 10, 50);
    //draw buy panel
    for (int i=0; i<purchaseShips.length; i++) {
      ofSetColor(78,174, 187);
      ofFill();
      stroke(255);
      strokeWeight(2);
      rect(0+(i*(width/purchaseShips.length)),715, width/purchaseShips.length, 800);
      noStroke();
      ofSetColor(255);
      text(purchaseShips[i], 50+(i*(width/purchaseShips.length)), 750);
      text(shipCosts[i], 50+(i*(width/purchaseShips.length)), 785);
   }
     hiveShip.display("enemy");

  if (player.shipDead) {
    textSize(60);
    text("YOU LOSE!", 200, 200);
  } else {
    player.display("player");
    if (hiveShip.shipDead) {
      textSize(60);
      text("YOU WIN!", 200, 200);
    } else {
      hiveShip.display("enemy");
    }
  }

// check to see if game is over
  if(enShots.size() !=0){
    for (int i=0; i<=enShots.size(); i++) {
      Shot tempShot = enShots[i];
      player.gotShot(tempShot, i, "player");
    }
  }

  if (player.shipDead == false && playerShip.size() !=0) {
    for(int i=0; i<=playerShots.size(); i++) {
     Shot tempShot = playerShots[i];
     hiveShip.gotShot(tempShot, i, "enemy");
    }
  }



}

//--------------------------------------------------------------
void ofApp::draw(){
       // draw shots
    if(enShots.size() != 0) {
      for (int i = 0; i<enShots.size(); i++) {
        // ignore !ifActive
        Shot tempShot = enShots[i];
        if(tempShot.isActive) {
          tempShot.update();
          tempShot.display();
        }
      }
    }
    if(playerShots.size() !=0) {
      for (int i = 0; i<playerShots.size(); i++) {
        Shot tempShot = playerShots[i];
        if(tempShot.isActive) {
          tempShot.update();
          tempShot.display();
        }
      }
    }
    //  draw enemy ships
     for (int i = 0; i < enemyShip.size(); i++) {
       Ships tempEnemy = enemyShip[i]);
       tempEnemy.update();
       tempEnemy.display();
       tempEnemy.shoot();
       if(playerShip.size() != 0){
         for (int j = 0; j<playerShots.size(); j++) {
           Shot tempShot = playerShots.[j];
           if (tempShot.isActive) {
             printf("Checking for shot at enemy");
            tempEnemy.gotShot(tempShot, tempEnemy, enemyShip, i, j, "player");
           }
        }
       }
     }

    // draw player ships
      if (playerShip.size() !=0) {
        for (int i = 0; i < playerShip.size(); i++) {
         Ships tempPlayer = playerShip[i];
         tempPlayer.update();
         tempPlayer.display();
         tempPlayer.shoot();
         if(enShots.size() !=0) {
           for (int j = 0; j<enShots.size(); j++) {
              Shot tempShot = enShots[j];
             if (tempShot.isActive ) {
              tempPlayer.gotShot(tempShot, tempPlayer, enemyShip, i, j, "enemy");
             }
           }
        }
       }
     }

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(y>715) {
    for (int i=0; i<purchaseShips.length; i++) {
      int tempLeftLine = i*(width/purchaseShips.length);
      int tempRightLine = (i+1)*(width/purchaseShips.length);
       if(tempLeftLine < x &&  x < tempRightLine  && shipCosts[i] <= resources ) {
        resources -= shipCosts[i];
        ofVec2f tempVec = new ofVec2f();
        tempVec.x = random(25, (width-25));
        tempVec.y = random(675, 700);
        string tempType = purchaseShips[i];
        playerShip.add(new Ships(tempVec,tempType,"player"));
      }

    noStroke();
    ofSetColor(255);
    text(purchaseShips[i], 50+(i*(width/purchaseShips.length)), 750);
    text(shipCosts[i], 50+(i*(width/purchaseShips.length)), 785);
  }
  }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
