//  bar.cpp
//  OOP_Project_Practice
//  Created by Harshvir Mangla on 28/10/24.

//#include<iostream>
//#include<SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//
//double max(double* arr, unsigned int length){
//    double m = arr[0];
//    for(int i = 0; i < length; i++){
//        if(arr[i] > m) m = arr[i];
//    }
//    return m;
//}
//
//bool pointToBar(const RectangleShape& bar, const Vector2f& mouseP){
//    return bar.getGlobalBounds().contains(mouseP);
//}
//
//class BarGraph{
//private:
//    RenderWindow* hm;
//    unsigned int wl = 1000;
//    unsigned int ww = 800;
//    unsigned int items;
//    unsigned int margin_l = 0.08 * wl;
//    unsigned int margin_w = 0.08 * ww;
//    double* heights;
//    RectangleShape* bars;
//    Text* labels;
//    double block_x;
//    Font font;
//    RectangleShape* y_axis;
//    RectangleShape* x_axis;
//    Color* bar_col;
//    unsigned int num_ticks = 8;
//    RectangleShape* ticks;
//    Text* tick_labels;
//    ConvexShape* x_tri;
//    ConvexShape* y_tri;
//    
//public:
//    BarGraph(unsigned int num){
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Bar Graph");
//        items = num;
//        heights = new double[items];
//        block_x = wl / items;
//        bars = new RectangleShape[num];
//        labels = new Text[num];
//        ticks = new RectangleShape[num_ticks];
//        tick_labels = new Text[num_ticks];
//        x_tri = new ConvexShape;
//        y_tri = new ConvexShape;
//        bar_col = new Color(13, 138, 191);
//
//    }
//    
//    BarGraph(unsigned int num, unsigned int pix_l, unsigned int pix_w, string color = "blue", unsigned int ticks_number = 8){
//        items = num;
//        heights = new double[items];
//        wl = pix_l;
//        ww = pix_w;
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Bar Graph");
//        bars = new RectangleShape[num];
//        margin_l = 0.08 * wl;
//        margin_w = 0.08 * ww;
//        block_x = wl / items - margin_l / items;
//        labels = new Text[num];
//        num_ticks = ticks_number;
//        ticks = new RectangleShape[num_ticks];
//        tick_labels = new Text[num_ticks];
//        x_tri = new ConvexShape;
//        y_tri = new ConvexShape;
//        
//        if(color == "blue") bar_col = new Color(13, 138, 191);
//        else if(color == "green") bar_col = new Color(32, 135, 23);
//        else if(color == "red") bar_col = new Color(186, 9, 24);
//        else if(color ==  "brown") bar_col = new Color(189, 77, 25);
//        else if(color == "pink") bar_col = new Color(237, 71, 196);
//        else{
//            cerr << "Invalid color" << endl;
//            bar_col = new Color(255, 255, 255);
//        }
//    }
//    
//    void make_bars(double* h, string* classes){
//        string font_path = "/System/Library/Fonts/Geneva.ttf";
//        font.loadFromFile(font_path);
//        for(int i = 0; i < items; i++){
//            heights[i] = h[i];
//        }
//        
//        for(int i = 0; i < items; i++){
//            bars[i] = RectangleShape(Vector2f(block_x / 2, heights[i] / max(heights, items) * 0.6 * ww));
//            bars[i].setPosition(i * block_x + margin_l, ww * 0.6 + margin_w - heights[i] / max(heights, items) * 0.6 * ww);
//            bars[i].setFillColor(*bar_col);
//            
//            labels[i] = Text(classes[i], font, 25);
//            labels[i].setFillColor(Color :: White);
//            labels[i].setRotation(55);
//            labels[i].setPosition(margin_l + i * block_x + 0.25 * block_x, ww * 0.6 + margin_w + 20);
//        }
//        y_axis = new RectangleShape(Vector2f(block_x / 60, 0.6 * ww + 0.3 * margin_w));
//        y_axis -> setPosition(0.5 * margin_l, margin_w * 0.7);
//        y_axis -> setFillColor(Color :: White);
//        x_axis = new RectangleShape(Vector2f((items - 0.3) * block_x + 0.5 * margin_l, block_x / 60));
//        x_axis -> setPosition(0.5 * margin_l, margin_w + 0.6 * ww);
//        
//        make_ticks();
//        make_arrows();
//    }
//    
//    void make_ticks(){
//        double tick_gap = 0.6 * ww / num_ticks;
//        double tick_numeric_gap = max(heights, items) / num_ticks;
//        for(int i = 0; i < num_ticks; i++){
//            ticks[i] = RectangleShape(Vector2f(block_x / 30, block_x / 90));
//            ticks[i].setPosition(0.5 * margin_l - block_x / 120, i * tick_gap + margin_w);
//            ticks[i].setFillColor(Color(253, 255, 124));
//            
//            string lab = to_string(max(heights, items) - i * tick_numeric_gap);
//            tick_labels[i] = Text(lab.substr(0, 5), font, 10);
//            tick_labels[i].setPosition(0.2 * margin_l, i * tick_gap + margin_w - block_x / 120);
//            tick_labels[i].setFillColor(Color(253, 255, 124));
//        }
//    }
//    
//    void make_arrows(){
//        x_tri -> setPointCount(3);
//        x_tri -> setPoint(0, Vector2f(0, 0));
//        x_tri -> setPoint(1, Vector2f(-block_x / 30, block_x / 30));
//        x_tri -> setPoint(2, Vector2f(-block_x / 30, -block_x / 30));
//        x_tri -> setPosition(0.5 * margin_l + (items - 0.3) * block_x + 0.5 * margin_l + block_x / 30, margin_w + 0.6 * ww + block_x / 120);
//        x_tri -> setFillColor(Color :: White);
//        
//        y_tri -> setPointCount(3);
//        y_tri -> setPoint(0, Vector2f(0, 0));
//        y_tri -> setPoint(1, Vector2f(-block_x / 30, block_x / 30));
//        y_tri -> setPoint(2, Vector2f(block_x / 30, block_x / 30));
//        y_tri -> setPosition(0.5 * margin_l + block_x / 120, margin_w * 0.7 - block_x / 30);
//        y_tri -> setFillColor(Color :: White);
//    }
//    
//    void set_ticks(unsigned int number_ticks){
//        num_ticks = number_ticks;
//        delete[] ticks;
//        delete[] tick_labels;
//        
//        ticks = new RectangleShape[num_ticks];
//        tick_labels = new Text[num_ticks];
//    }
//    
//    bool open(){
//        return hm -> isOpen();
//    }
//    
//    void change_color(string color){
//        delete bar_col;
//        if(color == "blue") bar_col = new Color(13, 138, 191);
//        else if(color == "green") bar_col = new Color(32, 135, 23);
//        else if(color == "red") bar_col = new Color(186, 9, 24);
//        else if(color ==  "brown") bar_col = new Color(189, 77, 25);
//        else if(color == "pink") bar_col = new Color(237, 71, 196);
//        else{
//            cerr << "Invalid color" << endl;
//            bar_col = new Color(255, 255, 255);
//        }
//        
//        for(int i = 0; i < items; i++){
//            bars[i].setFillColor(*bar_col);
//        }
//    }
//    
//    void display(){
//        unsigned int h_bar_index = -1;
//        while(hm -> isOpen()){
//            Event eve;
//            while(hm -> pollEvent(eve)){
//                if(eve.type == Event :: Closed){
//                    hm -> close();
//                }
//                
//                if(eve.type == Event :: MouseButtonPressed){
//                    Vector2f mousePosition = hm -> mapPixelToCoords(Mouse :: getPosition(*hm));
//                    for(int i = 0; i < items; i++){
//                        if(pointToBar(bars[i], mousePosition)){
//                            if(h_bar_index == i){
//                                bars[h_bar_index].setFillColor(*bar_col);
//                            }
//                            else{
//                                h_bar_index = i;
//                                bars[h_bar_index].setFillColor(Color :: White);
//                            }
//                            break;
//                        }
//                    }
//                }
//            }
//        
//            hm -> clear();
//            for(int i = 0; i < items; i++){
//                hm -> draw(bars[i]);
//                hm -> draw(labels[i]);
//                hm -> draw(*y_axis);
//                hm -> draw(*x_axis);
//            }
//            hm -> draw(*x_tri);
//            hm -> draw(*y_tri);
//            
//            for(int i = 0; i < num_ticks; i++){
//                hm -> draw(ticks[i]);
//                hm -> draw(tick_labels[i]);
//            }
//            hm -> display();
//        }
//    }
//};
//
//int main(){
//    BarGraph hm(6, 1000, 1000);
//    double hm_h[6] = {210, 10, 29, 4, 56, 41};
//    string arr[6] = {"Jawa", "RF", "Hayabusa", "Kawasaki", "Harley", "Yezdi"};
//    hm.set_ticks(20);
//    hm.make_bars(hm_h, arr);
//    hm.change_color("red");
//    hm.display();
//    return 0;
//}
