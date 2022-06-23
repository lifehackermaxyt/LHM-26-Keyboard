/**
 * This turns the ESP32 into a Bluetooth LE keyboard
 */
#include <BleKeyboard.h>
#include <JC_Button.h>

BleKeyboard bleKeyboard("LHM26 Keydoard", "LifeHackerMax", 100);

int LAYER (0);

const unsigned long
    FIRST_PRESS_DELAY(300),
    REPEAT_FIRST(40),              // ms required before repeating on long press
    REPEAT_INCR(80),             // repeat interval for long press
    debounceDelay(15);
    
Button btn1(23, debounceDelay, true, true);
Button btn2(22, debounceDelay, true, true);
Button btn3(21, debounceDelay, true, true);
Button btn4(5, debounceDelay, true, true);
Button btn5(17, debounceDelay, true, true);
Button btn6(13, debounceDelay, true, true);
Button btn7(10, debounceDelay, true, true);
Button btn8(14, debounceDelay, true, true);
Button btn9(26, debounceDelay, true, true);
Button btn10(33, debounceDelay, true, true);
Button btn11(18, debounceDelay, true, true);
Button btn12(19, debounceDelay, true, true);
Button btn13(16, debounceDelay, true, true);
Button btn14(4, debounceDelay, true, true);
Button btn15(34, debounceDelay, false, true);
Button btn16(9, debounceDelay, true, true);
Button btn17(12, debounceDelay, true, true);
Button btn18(27, debounceDelay, true, true);
Button btn19(25, debounceDelay, true, true);
Button btn20(32, debounceDelay, true, true);
Button btn21(35, debounceDelay, false, true);
Button btn22(36, debounceDelay, false, true);
Button btn23(39, debounceDelay, false, true);
Button btn24(0, debounceDelay, true, true);
Button btn25(2, debounceDelay, true, true);
Button btn26(15, debounceDelay, true, true);
//char key2map[][20] = {"a","1",KEY_TAB,KEY_F1};
//char key3map[][20] = {"d", "2", ",", KEY_F1};

void setup() {
  
  Serial.begin(115200);
  
btn1.begin();
btn2.begin();
btn3.begin();
btn4.begin();
btn5.begin();
btn6.begin();
btn7.begin();
btn8.begin();
btn9.begin();
btn10.begin();
btn11.begin();
btn12.begin();
btn13.begin();
btn14.begin();
btn15.begin();
btn16.begin();
btn17.begin();
btn18.begin();
btn19.begin();
btn20.begin();
btn21.begin();
btn22.begin();
btn23.begin();
btn24.begin();
btn25.begin();
btn26.begin();

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

}


void loop() {
  
    static unsigned long 
     rpt1(REPEAT_FIRST),
     rpt2(REPEAT_FIRST),   
     rpt3(REPEAT_FIRST), 
     rpt4(REPEAT_FIRST), 
     rpt5(REPEAT_FIRST), 
     rpt6(REPEAT_FIRST), 
     rpt7(REPEAT_FIRST), 
     rpt8(REPEAT_FIRST), 
     rpt9(REPEAT_FIRST), 
     rpt10(REPEAT_FIRST), 
     rpt11(REPEAT_FIRST), 
     rpt12(REPEAT_FIRST), 
     rpt13(REPEAT_FIRST), 
     rpt14(REPEAT_FIRST), 
     rpt15(REPEAT_FIRST), 
     rpt16(REPEAT_FIRST), 
     rpt17(REPEAT_FIRST), 
     rpt18(REPEAT_FIRST), 
     rpt19(REPEAT_FIRST), 
     rpt20(REPEAT_FIRST), 
     rpt21(REPEAT_FIRST), 
     rpt22(REPEAT_FIRST), 
     rpt23(REPEAT_FIRST),
     rpt24(REPEAT_FIRST), 
     rpt25(REPEAT_FIRST), 
     rpt26(REPEAT_FIRST);
 
        btn1.read();
        btn2.read();
        btn3.read();
        btn4.read();
        btn5.read();
        btn6.read();
        btn7.read();
        btn8.read();
        btn9.read();
        btn10.read();
        btn11.read();
        btn12.read();
        btn13.read();
        btn14.read();
        btn15.read();
        btn16.read();
        btn17.read();
        btn18.read();
        btn19.read();
        btn20.read();
        btn21.read();
        btn22.read();
        btn23.read();
        btn24.read();
        btn25.read();
        btn26.read();

     static int lastLayer(0);
     static int interLayer(0);
     Serial.println(LAYER);    

     if (btn1.wasReleased()) rpt1 = REPEAT_FIRST;
     if (btn2.wasReleased()) rpt2 = REPEAT_FIRST;
     if (btn3.wasReleased()) rpt3 = REPEAT_FIRST;
     if (btn4.wasReleased()) rpt4 = REPEAT_FIRST;
     if (btn5.wasReleased()) rpt5 = REPEAT_FIRST;
     if (btn6.wasReleased()) rpt6 = REPEAT_FIRST;
     if (btn7.wasReleased()) rpt7 = REPEAT_FIRST;
     if (btn8.wasReleased()) rpt8 = REPEAT_FIRST;
     if (btn9.wasReleased()) rpt9 = REPEAT_FIRST;
     if (btn10.wasReleased()) rpt10 = REPEAT_FIRST;
     if (btn11.wasReleased()) rpt11 = REPEAT_FIRST;
     if (btn12.wasReleased()) rpt12 = REPEAT_FIRST;
     if (btn13.wasReleased()) rpt13 = REPEAT_FIRST;
     if (btn14.wasReleased()) rpt14 = REPEAT_FIRST;
     if (btn15.wasReleased()) rpt15 = REPEAT_FIRST;
     if (btn16.wasReleased()) rpt16 = REPEAT_FIRST;
     if (btn17.wasReleased()) rpt17 = REPEAT_FIRST;
     if (btn18.wasReleased()) rpt18 = REPEAT_FIRST;
     if (btn19.wasReleased()) rpt19 = REPEAT_FIRST;
     if (btn20.wasReleased()) rpt20 = REPEAT_FIRST;
     if (btn21.wasReleased()) rpt21 = REPEAT_FIRST;
     if (btn22.wasReleased()) rpt22 = REPEAT_FIRST;
     if (btn23.isReleased()) {
            if(btn24.isReleased()){
              if (lastLayer != interLayer){
                lastLayer = interLayer;
              }
            }
      LAYER = lastLayer;
      rpt23 = REPEAT_FIRST;
     }
     if (btn24.isReleased()) {
            if(btn23.isReleased()){
              if (lastLayer != interLayer){
               lastLayer = interLayer;
     }     
            }
      LAYER = lastLayer;
      rpt24 = REPEAT_FIRST;
     }
     if (btn25.wasReleased()) rpt25 = REPEAT_FIRST;
     if (btn26.wasReleased()) rpt26 = REPEAT_FIRST;
         
if(bleKeyboard.isConnected()) {
/*
if (LAYER == 0){
  Serial.write('0');
}
if (LAYER == 1){
  Serial.write('1');
}
if (LAYER == 2){
  Serial.write("2");
}
if (LAYER == 3){
  Serial.write("3");
}
*/
// Changing Layers ------------------------------------------------------------------
  
    if (lastLayer == 0){
           
        if(btn23.isPressed() &&  btn24.isReleased()){  
          LAYER = 1;
        }
        if(btn24.isPressed() &&  btn23.isReleased()){  
          LAYER = 2;
        } 
        if(btn24.isPressed() &&  btn23.isPressed()){  
          LAYER = 3;
       }
    }
   
    if (lastLayer == 1){
        
        if(btn23.isPressed() &&  btn24.isReleased()){  
          LAYER = 0;
        }
        if(btn24.isPressed() &&  btn23.isReleased()){  
          LAYER = 2;
        }
        if(btn24.isPressed() &&  btn23.isPressed()){  
          LAYER = 3;
       }
    }

    if (lastLayer == 2){
      
        if(btn23.isPressed() &&  btn24.isReleased()){  
          LAYER = 0;
        }
        if(btn24.isPressed() &&  btn23.isReleased()){  
          LAYER = 1;
        }
        if(btn24.isPressed() &&  btn23.isPressed()){  
          LAYER = 3;
       }
    }

        if (lastLayer == 3){
    
        if(btn23.isPressed() &&  btn24.isReleased()){  
          LAYER = 0;
        }
        if(btn24.isPressed() &&  btn23.isReleased()){  
          LAYER = 1;
        }
        if(btn24.isPressed() &&  btn23.isPressed()){  
          LAYER = 2;
       }
    }

    if (btn11.pressedFor(rpt11)) {           
         if (rpt11 != REPEAT_FIRST) { 
             rpt11 += REPEAT_INCR;    
         }
          else{
          rpt11 += FIRST_PRESS_DELAY;
         }      

    if((btn1.isPressed() &&  btn23.isPressed()) || (btn1.isPressed() &&  btn24.isPressed() || btn1.isPressed() &&  btn23.isPressed() &&  btn24.isPressed())){  
//       lastLayer = LAYER;
       interLayer = LAYER;
    }   
   }  
}

// button1 ----------------------------------------------------------------                     
    
     if (btn1.pressedFor(rpt1)) {           
         if (rpt1 != REPEAT_FIRST) { 
             rpt1 += REPEAT_INCR;    
         }
          else{
          rpt1 += FIRST_PRESS_DELAY;
         }      
    if(btn23.isReleased() && btn24.isReleased())  { 

          bleKeyboard.write(KEY_ESC);
        }
    }  

// Button 2 ----------------------------------------------------------------

     if (btn2.pressedFor(rpt2)) {           
         if (rpt2 != REPEAT_FIRST) { 
             rpt2 += REPEAT_INCR;    
         }
          else{
          rpt2 += FIRST_PRESS_DELAY;
         }      
        if(btn12.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("a");
          if (LAYER == 1) bleKeyboard.print("1");
          if (LAYER == 2) bleKeyboard.write(KEY_TAB);
          if (LAYER == 3) bleKeyboard.write(KEY_F1);
        }
        if(btn12.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("b");
          if (LAYER == 1) bleKeyboard.print("!");
//          if (LAYER == 2) bleKeyboard.write(KEY_TAB);
//          if (LAYER == 3) bleKeyboard.write(KEY_F1);
        }         
     }

// Button 3 ----------------------------------------------------------------

     if (btn3.pressedFor(rpt3)) {
         if (rpt3 != REPEAT_FIRST) { 
             rpt3 += REPEAT_INCR;    
         }
          else{
          rpt3 += FIRST_PRESS_DELAY;
         }
        if(btn13.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("d");
          if (LAYER == 1) bleKeyboard.print("2");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
          if (LAYER == 3) bleKeyboard.write(KEY_F2);
        }
        if(btn13.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("j");
          if (LAYER == 1) bleKeyboard.print("@");
          if (LAYER == 2) bleKeyboard.print("<");
//          if (LAYER == 3) bleKeyboard.write(KEY_F2);
        }  
     }

// Button 4 ----------------------------------------------------------------

     if (btn4.pressedFor(rpt4)) {
      
        if (rpt4 != REPEAT_FIRST) { 
             rpt4 += REPEAT_INCR;    
         }
          else{
          rpt4 += FIRST_PRESS_DELAY;
         }
         
        if(btn14.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("e");
          if (LAYER == 1) bleKeyboard.print("3");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          if (LAYER == 3) bleKeyboard.write(KEY_F3);
        }
        if(btn14.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("f");
          if (LAYER == 1) bleKeyboard.print("#");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_MUTE);
//          if (LAYER == 3) bleKeyboard.write(KEY_F3);
        }  
     }

// Button 5 ----------------------------------------------------------------

     if (btn5.pressedFor(rpt5)) {
      
         if (rpt5 != REPEAT_FIRST) { 
             rpt5 += REPEAT_INCR;    
         }
          else{
          rpt5 += FIRST_PRESS_DELAY;
         }
       
        if(btn6.isReleased() && btn15.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("h");
          if (LAYER == 1) bleKeyboard.print("4");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_UP);
          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
        if(btn6.isPressed() && btn15.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("q");
          if (LAYER == 1) bleKeyboard.print("(");
//          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_UP);
//          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
          if(btn6.isReleased() && btn15.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("z");
          if (LAYER == 1) bleKeyboard.print("$");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
//          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
    }

// Button 6 ----------------------------------------------------------------

     if (btn6.pressedFor(rpt6)) {
          
         if (rpt6 != REPEAT_FIRST) { 
             rpt6 += REPEAT_INCR;    
         }
          else{
          rpt6 += FIRST_PRESS_DELAY;
         }

        if(btn16.isReleased() && btn5.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("l");
          if (LAYER == 1) bleKeyboard.print("5");
          if (LAYER == 2) bleKeyboard.write(KEY_HOME);
          if (LAYER == 3) bleKeyboard.write(KEY_F5);
        }
        if(btn16.isPressed() && btn5.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("k");
          if (LAYER == 1) bleKeyboard.print("%");
//          if (LAYER == 2) bleKeyboard.write(KEY_HOME);
//          if (LAYER == 3) bleKeyboard.write(KEY_F5);
        }
    }

// Button 7 ----------------------------------------------------------------

     if (btn7.pressedFor(rpt7)) {
          
         if (rpt7 != REPEAT_FIRST) { 
             rpt7 += REPEAT_INCR;    
         }
          else{
          rpt7 += FIRST_PRESS_DELAY;
         }

        if(btn17.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("n");
          if (LAYER == 1) bleKeyboard.print("6");
          if (LAYER == 2) bleKeyboard.write(KEY_UP_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F6);
        }
        if(btn17.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("m");
          if (LAYER == 1) bleKeyboard.print("^");
//          if (LAYER == 2) bleKeyboard.write(KEY_UP_ARROW);
//          if (LAYER == 3) bleKeyboard.write(KEY_F6);
        }
  
    }
      
// Button 8 ----------------------------------------------------------------     

     if (btn8.pressedFor(rpt8)) {
          
         if (rpt8 != REPEAT_FIRST) { 
             rpt8 += REPEAT_INCR;    
         }
          else{
          rpt8 += FIRST_PRESS_DELAY;
         }

        if(btn18.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("r");
          if (LAYER == 1) bleKeyboard.print("7");
          if (LAYER == 2) bleKeyboard.write(KEY_END);
          if (LAYER == 3) bleKeyboard.write(KEY_F7);
        }   
        if(btn18.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("p");
          if (LAYER == 1) bleKeyboard.print("&");
//          if (LAYER == 2) bleKeyboard.write(KEY_END);
//          if (LAYER == 3) bleKeyboard.write(KEY_F7);
        }   

     }

// Button 9 ----------------------------------------------------------------

     if (btn9.pressedFor(rpt9)) {
          
         if (rpt9 != REPEAT_FIRST) { 
             rpt9 += REPEAT_INCR;    
         }
          else{
          rpt9 += FIRST_PRESS_DELAY;
         }
          if(btn19.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("o");
          if (LAYER == 1) bleKeyboard.print("8");
          if (LAYER == 2) bleKeyboard.write(KEY_DELETE);
          if (LAYER == 3) bleKeyboard.write(KEY_F8);
        }   
        if(btn19.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("y");
          if (LAYER == 1) bleKeyboard.print("*");
//          if (LAYER == 2) bleKeyboard.write(KEY_DELETE);
//          if (LAYER == 3) bleKeyboard.write(KEY_F8);
        }   
    }
    
// Button 10 ---------------------------------------------------------------

   if (btn10.pressedFor(rpt10)) {   
         
         if (rpt10 != REPEAT_FIRST) { 
             rpt10 += REPEAT_INCR;    
         }
          else{
          rpt10 += FIRST_PRESS_DELAY;
         }
      bleKeyboard.write(KEY_BACKSPACE);
   }
   
// Button 11 ---------------------------------------------------------------

   if(btn11.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_CTRL);
    }
    if(btn11.wasReleased()) {
      bleKeyboard.release(KEY_LEFT_CTRL);
    }

// Button 12 ---------------------------------------------------------------

     if (btn12.pressedFor(rpt12)) {
              
         if (rpt12 != REPEAT_FIRST) { 
             rpt12 += REPEAT_INCR;    
         }
          else{
          rpt12 += FIRST_PRESS_DELAY;
         }
            if(btn2.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("c");
          if (LAYER == 1) bleKeyboard.print("/");
          if (LAYER == 2) bleKeyboard.write(KEY_CAPS_LOCK);
          if (LAYER == 3) bleKeyboard.print(",");
        }   
     }

// Button 13 ---------------------------------------------------------------

     if (btn13.pressedFor(rpt13)) {
          
         if (rpt13 != REPEAT_FIRST) { 
             rpt13 += REPEAT_INCR;    
         }
          else{
          rpt13 += FIRST_PRESS_DELAY;
         }
                
        if(btn3.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("v");
          if (LAYER == 1) bleKeyboard.print("[");
          if (LAYER == 2) bleKeyboard.write(KEY_LEFT_GUI);
          if (LAYER == 3) bleKeyboard.print(".");
        }   
     }

// Button 14 ---------------------------------------------------------------

     if (btn14.pressedFor(rpt14))  {
          
         if (rpt14 != REPEAT_FIRST) { 
             rpt14 += REPEAT_INCR;    
         }
          else{
          rpt14 += FIRST_PRESS_DELAY;
         }
         
         if(btn4.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("g");
          if (LAYER == 1) bleKeyboard.print("]");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          if (LAYER == 3) bleKeyboard.print(";");
        }   
     }

// Button 15 ---------------------------------------------------------------

     if (btn15.pressedFor(rpt15)) {
          
         if (rpt15 != REPEAT_FIRST) { 
             rpt15 += REPEAT_INCR;    
         }
          else{
          rpt15 += FIRST_PRESS_DELAY;
         }
         
          if(btn5.isReleased() && btn16.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("i");
          if (LAYER == 1) bleKeyboard.print("\\");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
          if (LAYER == 3) bleKeyboard.print("'");
         } 
                  
          if(btn5.isReleased() && btn16.isPressed()) {
          if (LAYER == 0) bleKeyboard.print("x");
          if (LAYER == 1) bleKeyboard.print(")");
//          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
//          if (LAYER == 3) bleKeyboard.print("'");
         }      

     }   

// Button 16 ---------------------------------------------------------------
    
     if (btn16.pressedFor(rpt16)) {
          
         if (rpt16 != REPEAT_FIRST) { 
             rpt16 += REPEAT_INCR;    
         }
          else{
          rpt16 += FIRST_PRESS_DELAY;
         }
         
         if(btn15.isReleased() && btn6.isReleased()){
          if (LAYER == 0) bleKeyboard.print("s");
          if (LAYER == 1) bleKeyboard.print("=");
          if (LAYER == 2) bleKeyboard.write(KEY_LEFT_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F12);
        }   
 
    }  

// Button 17 ---------------------------------------------------------------

    if (btn17.pressedFor(rpt17)) {
          
         if (rpt17 != REPEAT_FIRST) { 
             rpt17 += REPEAT_INCR;    
         }
          else{
          rpt17 += FIRST_PRESS_DELAY;
         }
         
        if(btn7.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("t");
          if (LAYER == 1) bleKeyboard.print("-");
          if (LAYER == 2) bleKeyboard.write(KEY_DOWN_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F11);
        }          
    }     

// Button 18 ---------------------------------------------------------------

    if (btn18.pressedFor(rpt18)) {
          
         if (rpt18 != REPEAT_FIRST) { 
             rpt18 += REPEAT_INCR;    
         }
          else{
          rpt18 += FIRST_PRESS_DELAY;
         }
         
        if(btn8.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("u");
          if (LAYER == 1) bleKeyboard.print("0");
          if (LAYER == 2) bleKeyboard.write(KEY_RIGHT_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F10);
        }          
    } 

// Button 19 ---------------------------------------------------------------

        if (btn19.pressedFor(rpt19)) {
          
         if (rpt19 != REPEAT_FIRST) { 
             rpt19 += REPEAT_INCR;    
         }
          else{
          rpt19 += FIRST_PRESS_DELAY;
         }
         
        if(btn9.isReleased()) {
          if (LAYER == 0) bleKeyboard.print("w");
          if (LAYER == 1) bleKeyboard.print("9");
          if (LAYER == 2) bleKeyboard.write(KEY_INSERT);
          if (LAYER == 3) bleKeyboard.write(KEY_F9);
        }          
    } 

// Button 20 ---------------------------------------------------------------
       
     if (btn20.pressedFor(rpt20)) {   
         
         if (rpt20 != REPEAT_FIRST) { 
             rpt20 += REPEAT_INCR;    
         }
          else{
          rpt20 += FIRST_PRESS_DELAY;
         }
      bleKeyboard.write(KEY_RETURN);
    }

// Button 21 ---------------------------------------------------------------

    
    if(btn21.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_SHIFT);
    }
    if(btn21.wasReleased()) {
      bleKeyboard.release(KEY_LEFT_SHIFT);
    }


// Button 22 ---------------------------------------------------------------

    if(btn22.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
    }
    if(btn22.wasReleased()) {
      bleKeyboard.release(KEY_LEFT_ALT);
    }


// Button 23 FN1 KEY -------------------------------------------------------



// Button 24 FN2 KEY -------------------------------------------------------



// Button 25 ---------------------------------------------------------------

   if (btn25.pressedFor(rpt25)) {   
         
         if (rpt25 != REPEAT_FIRST) { 
             rpt25 += REPEAT_INCR;    
         }
          else{
          rpt25 += FIRST_PRESS_DELAY;
         }
      bleKeyboard.print(" ");
    }  

// Button 26 ---------------------------------------------------------------

      
    if(btn26.wasPressed()) {
      bleKeyboard.press(KEY_RIGHT_SHIFT);
    }
    if(btn26.wasReleased()) {
      bleKeyboard.release(KEY_RIGHT_SHIFT);
    }        

// THE END -----------------------------------------------------------------
}
