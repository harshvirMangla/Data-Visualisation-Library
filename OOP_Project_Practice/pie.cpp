//  pie.cpp
//  OOP_Project_Practice
//  Created by Harshvir Mangla on 01/11/24.

//#include<iostream>
//#include<SFML/Graphics.hpp>
//#define PI 3.14159
//using namespace std;
//using namespace sf;
//
//class PieChart{
//private:
//    RenderWindow* hm;
//    double wl = 1000;
//    double ww = 800;
//    unsigned int margin_l = 0.08 * wl;
//    unsigned int margin_w = 0.08 * ww;
//    Font font;
//    Vector2f* center;
//    double* values;
//    string* classes;
//    unsigned int number;
//    unsigned int radius;
//    ConvexShape** sectors;
//    unsigned int point_num = 1000;
//    Color** colors;
//    Text* labels;
//    
//public:
//    PieChart(unsigned int data_points){
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Pie Chart");
//        number = data_points;
//        values = new double[number];
//        classes = new string[number];
//        center = new Vector2f(wl / 2, ww / 2);
//        radius = (wl < ww)? 0.3 * wl : 0.3 * ww;
//        sectors = new ConvexShape*[number];
//        colors = new Color*[5];
//        labels = new Text[number];
//    }
//    
//    PieChart(unsigned int data_points, unsigned int pix_l, unsigned int pix_w){
//        wl = pix_l;
//        ww = pix_w;
//        margin_l = 0.08 * wl;
//        margin_w = 0.08 * ww;
//        
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Pie Chart");
//        number = data_points;
//        values = new double[number];
//        classes = new string[number];
//        labels = new Text[number];
//        center = new Vector2f(wl / 2, ww / 2);
//        radius = (wl < ww)? 0.3 * wl : 0.3 * ww;
//        sectors = new ConvexShape*[number];
//        colors = new Color*[5];
//    }
//    
//    void make_pie(double* data, string* classes_arr){
//        store_data(data, classes_arr);
//        make_labels();
//        double total = 0;
//        for(int i = 0; i < number; i++){
//            total += values[i];
//        }
//        
//        colors[0] = new Color(135, 206, 250);
//        colors[1] = new Color(240, 128, 128);
//        colors[2] = new Color(152, 251, 152);
//        colors[3] = new Color(250, 250, 210);
//        colors[4] = new Color(216, 191, 216);
//        
//        double start_angle = 0;
//        
//        for(int i = 0; i < number; i++){
//            sectors[i] = new ConvexShape(point_num);
//            double angle = data[i] / total;
//            sectors[i] -> setPoint(0, *center);
//            
//            for(int point = 0; point < point_num - 1; point++){
//                double current_angle = start_angle + (point * (angle / point_num - 2));
//                sectors[i] -> setPoint(point + 1, Vector2f(center -> x + radius * cos(current_angle * PI * 2), center -> y + radius * sin(current_angle * PI * 2)));
//            }
//            
//            sectors[i] -> setFillColor(*colors[i % 4]);
//            start_angle += angle;
//        }
//        
//    }
//    
//    void store_data(double * data, string* classes_arr){
//        for(int i = 0; i < number; i++){
//            values[i] = data[i];
//            classes[i] = classes_arr[i];
//        }
//    }
//    
//    void make_labels(){
//        string font_path = "/System/Library/Fonts/Geneva.ttf";
//        font.loadFromFile(font_path);
//        for(int i = 0; i < number; i++){
//            labels[i] = Text(classes[i].substr(0, 10), font, 20);
//            labels[i].setFillColor(Color :: Red);
//            if(ww > 300){
//                if(30 < radius / 2){
//                    labels[i].setPosition(wl / 2 - 30, ww / 2 - radius - 30);
//                }
//                else{
//                    labels[i].setPosition(wl / 2 - radius / 2, ww / 2 - radius - radius / 2);
//                }
//            }
//            else{
//                labels[i].setPosition(0.12 * wl, 10);
//            }
//        }
//    }
//    
//    bool pointsToSector(const Vector2f& mousePos, unsigned int sec_index){
//        double dx = mousePos.x - center -> x;
//        double dy = mousePos.y - center -> y;
//        double distance = sqrt(dx * dx + dy * dy);
//        
//        if(distance > radius){
//            return false;
//        }
//        
//        double total = 0;
//        for(int i = 0; i < number; i++){
//            total += values[i];
//        }
//        double startAngle = 0;
//        for(int i = 0; i < sec_index; i++){
//            startAngle += (values[i] / total) * 2 * PI;
//        }
//        
//        double endAngle = startAngle + (values[sec_index] / total) * 2 * PI;
//        double mouseAngle = atan2(dy, dx);
//        if(mouseAngle < 0) mouseAngle += 2 * PI;
//        
//        if(mouseAngle >= startAngle && mouseAngle <= endAngle){
//            return true;
//        }
//        
//        return false;
//    }
//
//    
//    void display(){
//        unsigned int highlightedIndex = -1;
//        while(hm -> isOpen()){
//            Event eve;
//            while(hm -> pollEvent(eve)){
//                if(eve.type == Event :: Closed){
//                    hm -> close();
//                }
//                if(eve.type == Event :: MouseButtonPressed){
//                    for(int i = 0; i < number; i++){
//                        Vector2f mouse = hm -> mapPixelToCoords(Mouse :: getPosition(*hm));
//                        if(pointsToSector(mouse, i)){
//                            if(highlightedIndex == i){
//                                sectors[i] -> setFillColor(*colors[i % 4]);
//                                highlightedIndex = -1;
//                            }
//                            else{
//                                if(highlightedIndex == -1){
//                                    highlightedIndex = i;
//                                    sectors[i] -> setFillColor(Color :: Red);
//                                }
//                            }
//                        }
//                    }
//                    
//                }
//            }
//            
//            hm -> clear(Color :: Black);
//            
//            if(highlightedIndex != -1){
//                hm -> draw(labels[highlightedIndex]);
//            }
//            
//            for(int i = 0; i < number; i++){
//                hm -> draw(*sectors[i]);
//            }
//            
//            hm -> display();
//        }
//    }
//};
//
//int main(){
//    double d[5] = {100, 200, 30, 40, 50};
//    string c[5] = {"Ankush", "Pinchi", "Gourav", "Prabh", "Goma"};
//    PieChart hm(5, 1000, 800);
//    hm.make_pie(d, c);
//    hm.display();
//    return 0;
//}
