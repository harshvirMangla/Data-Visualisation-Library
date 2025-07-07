//  line.cpp
//  OOP_Project_Practice
//  Created by Harshvir Mangla on 29/10/24.

//#include<iostream>
//#include<random>
//#include<SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//
//
//unsigned int randomNumber(){
//    random_device hm;
//    mt19937 gen(hm());
//    uniform_int_distribution<int> distr(0, 255);
//    return distr(gen);
//}
//
//double min(double* p, unsigned int items){
//    double minm = p[0];
//    for(int i = 1; i < items; i++){
//        if(p[i] < minm) minm = p[i];
//    }
//    return minm;
//}
//
//double max(double* p, unsigned int items){
//    double maxm = p[0];
//    for(int i = 1; i < items; i++){
//        if(p[i] > maxm) maxm = p[i];
//    }
//    return maxm;
//}
//
//class LineGraph{
//private:
//    RenderWindow* hm;
//    double wl = 1000;
//    double ww = 800;
//    unsigned int points;
//    unsigned int margin_l = 0.08 * wl;
//    unsigned int margin_w = 0.08 * ww;
//    double* x_points;
//    double* y_points;
//    VertexArray* lGraph;
//    Font font;
//    Color* col;
//    RectangleShape* x_axis;
//    RectangleShape* y_axis;
//    bool isNegative = false;
//    bool isNegativeFound_y = false;
//    bool isNegativeFound_x = false;
//    bool areAllNegative_y = true;
//    bool areAllNegative_x = true;
//    unsigned int num_ticks = 8;
//    RectangleShape* x_ticks;
//    RectangleShape* y_ticks;
//    Text* x_labels;
//    Text* y_labels;
//    ConvexShape* arrows;
//    unsigned int num_lines = 0;
//    VertexArray* more_l;
//    
//public:
//    LineGraph(unsigned int num){
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Line Graph");
//        points = num;
//        x_points = new double[points];
//        y_points = new double[points];
//        lGraph = new VertexArray(LinesStrip, points);
//        col = new Color(15, 255, 79);
//        x_ticks = new RectangleShape[num_ticks];
//        y_ticks = new RectangleShape[num_ticks];
//        x_labels = new Text[num_ticks];
//        y_labels = new Text[num_ticks];
//        arrows = new ConvexShape[4];
//    }
//    
//    LineGraph(unsigned int num, double pix_l, double pix_w, unsigned int ticks_count = 8){
//        wl = pix_l;
//        ww = pix_w;
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Line Graph");
//        points = num;
//        x_points = new double[points];
//        y_points = new double[points];
//        lGraph = new VertexArray(LinesStrip, points);
//        margin_l = 0.08 * wl;
//        margin_w = 0.08 * ww;
//        col = new Color(15, 255, 79);
//        num_ticks = ticks_count;
//        x_ticks = new RectangleShape[num_ticks];
//        y_ticks = new RectangleShape[num_ticks];
//        x_labels = new Text[num_ticks];
//        y_labels = new Text[num_ticks];
//        arrows = new ConvexShape[4];
//    }
//    
//    void make_line(double* x, double* y){
//        store_points(x, y);
//        more_l = new VertexArray[5];
//        double max_x = max(x, points);
//        double min_x = min(x, points);
//        double max_y = max(y, points);
//        double min_y = min(y, points);
//        
//        for(int i = 0; i < points; i++){
//            if(y[i] < 0){
//                isNegativeFound_y = true;
//                break;
//            }
//        }
//        
//        for(int i = 0; i < points; i++){
//            if(x[i] < 0){
//                isNegativeFound_x = true;
//                break;
//            }
//        }
//        
//        for(int i = 0; i < points; i++){
//            if(y[i] > 0){
//                areAllNegative_y = false;
//                break;
//            }
//        }
//        
//        for(int i = 0; i < points; i++){
//            if(x[i] > 0){
//                areAllNegative_x = false;
//                break;
//            }
//        }
//        
//        if(areAllNegative_x && areAllNegative_y){
//            max_x = 0;
//            max_y = 0;
//        }
//        else if(areAllNegative_x){
//            max_x = 0;
//        }
//        else if(areAllNegative_y){
//            max_y = 0;
//        }
//        else{
//            max_x = max(x, points);
//            max_y = max(y, points);
//        }
//        
//        if(isNegativeFound_x && isNegativeFound_y){
//            min_x = min(x, points);
//            min_y = min(y, points);
//        }
//        else if(isNegativeFound_x){
//            min_y = 0;
//        }
//        else if(isNegativeFound_y){
//            min_x = 0;
//        }
//        else{
//            min_x = 0;
//            min_y = 0;
//        }
//        
//        for(int i = 0; i < points; i++){
//            (*lGraph)[i].position = Vector2f(margin_l + ((x[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((y[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//            (*lGraph)[i].color = *col;
//        }
//        
//        for(int i = 0; i < num_ticks; i++){
//            x_ticks[i] = RectangleShape(Vector2f(margin_w / 15, margin_w / 7));
//            x_ticks[i].setFillColor(Color :: White);
//            y_ticks[i] = RectangleShape(Vector2f(margin_w / 7, margin_w / 15));
//            y_ticks[i].setFillColor(Color :: White);
//        }
//        
//        make_axes();
//        make_ticks();
//        make_arrows();
//    }
//    
//    void store_points(double* x, double* y){
//        for(int i = 0; i < points; i++){
//            x_points[i] = x[i];
//            y_points[i] = y[i];
//        }
//    }
//    
//    void change_color(string color = "green"){
//        delete col;
//        if(color == "blue") col = new Color(3, 198, 252);
//        else if(color == "green") col = new Color(15, 255, 79);
//        else if(color == "red") col = new Color(Color :: Red);
//        else if(color ==  "brown") col = new Color(191, 65, 15);
//        else if(color == "pink") col = new Color(255, 5, 197);
//        else{
//            cerr << "Invalid color" << endl;
//            col = new Color(255, 255, 255);
//        }
//
//        for(int i = 0; i < points; i++){
//            (*lGraph)[i].color = *col;
//        }
//    }
//    
//    void add_line(double* l, double* m, unsigned int size){
//        more_l[num_lines++] = VertexArray(LineStrip, size);
//        double max_x = max(x_points, points);
//        double min_x = min(x_points, points);
//        double max_y = max(y_points, points);
//        double min_y = min(y_points, points);
//        
//        if(areAllNegative_x && areAllNegative_y){
//            max_x = 0;
//            max_y = 0;
//        }
//        else if(areAllNegative_x){
//            max_x = 0;
//        }
//        else if(areAllNegative_y){
//            max_y = 0;
//        }
//        else{
//            max_x = max(x_points, points);
//            max_y = max(y_points, points);
//        }
//        
//        if(isNegativeFound_x && isNegativeFound_y){
//            min_x = min(x_points, points);
//            min_y = min(y_points, points);
//        }
//        else if(isNegativeFound_x){
//            min_y = 0;
//        }
//        else if(isNegativeFound_y){
//            min_x = 0;
//        }
//        else{
//            min_x = 0;
//            min_y = 0;
//        }
//        
//        for(int i = 0; i < size; i++){
//            (more_l[num_lines - 1])[i].position = Vector2f(margin_l + ((l[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((m[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//            (more_l[num_lines - 1])[i].color = Color :: Green;
//        }
//    }
//    
//    void change_color(unsigned int line, string color){
//        Color col_changer;
//        if(color == "red"){
//            col_changer = Color(Color :: Red);
//        }
//        else if(color == "green"){
//            col_changer = Color(15, 255, 79);
//        }
//        else if(color == "blue"){
//            col_changer = Color(3, 198, 252);
//        }
//        else if(color == "brown"){
//            col_changer = Color(191, 65, 15);
//        }
//        else if(color == "pink"){
//            col_changer = Color(255, 5, 197);
//        }
//        else{
//            unsigned int r = randomNumber();
//            unsigned int g = randomNumber();
//            unsigned int b = randomNumber();
//            col_changer = Color(r, g, b);
//            cout << "Color of line " << line << " changed randomly." << endl;
//        }
//        
//        if(line == 0){
//            *col = col_changer;
//        }
//        else{
//            if(line <= num_lines){
//                for(int i = 0; i < more_l[line - 1].getVertexCount(); i++){
//                    more_l[line - 1][i].color = col_changer;
//                }
//            }
//            else{
//                cout << "Line index is out of bounds." << endl;
//            }
//        }
//    }
//    
//    void make_axes(){
//        double max_x = max(x_points, points);
//        double min_x = min(x_points, points);
//        double max_y = max(y_points, points);
//        double min_y = min(y_points, points);
//        
//        x_axis = new RectangleShape(Vector2f(wl - 1.5 * margin_l, margin_w / 15));
//        x_axis -> setFillColor(Color :: White);
//        
//        y_axis = new RectangleShape(Vector2f(margin_w / 15, ww - 1.5 * margin_w));
//        y_axis -> setFillColor(Color :: White);
//        
//        if(isNegativeFound_y && !areAllNegative_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - ((0 - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//        }
//        else if(isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, margin_w);
//        }
//        else if(!isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - margin_w);
//        }
//        
//        if(isNegativeFound_x && !areAllNegative_x){
//            y_axis -> setPosition(margin_l + ((0 - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), 0.75 * margin_w);
//        }
//        else if(isNegativeFound_x){
//            y_axis -> setPosition(wl - margin_l, 0.75 * margin_w);
//        }
//        else if(!isNegativeFound_x){
//            y_axis -> setPosition(margin_l, 0.75 * margin_w);
//        }
//        
//        for(int i = 0; i < 4; i++){
//            arrows[i] = ConvexShape();
//            arrows[i].setPointCount(3);
//            arrows[i].setFillColor(Color :: White);
//        }
//    }
//    
//    void make_ticks(){
//        string font_path = "/System/Library/Fonts/Geneva.ttf";
//        font.loadFromFile(font_path);
//        
//        double max_x = max(x_points, points);
//        double min_x = min(x_points, points);
//        double max_y = max(y_points, points);
//        double min_y = min(y_points, points);
//        
//        double tick_gap_x = (wl - 2 * margin_l) / (num_ticks - 1);
//        double tick_gap_y = (ww - 2 * margin_w) / (num_ticks - 1);
//        
//        double num_gap_x = 0;
//        double num_gap_y = 0;
//        
//        double base_tick_x = 0;
//        double base_tick_y = 0;
//        
//        if(isNegativeFound_y && !areAllNegative_y){
//            num_gap_y = (max_y - min_y) / (num_ticks - 1);
//            base_tick_y = min_y;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, ww - ((0 - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//        else if(isNegativeFound_y){
//            num_gap_y = (0 - min_y) / (num_ticks - 1);
//            base_tick_y = min_y;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//        else if(!isNegativeFound_y){
//            num_gap_y = (max_y - 0) / (num_ticks - 1);
//            base_tick_y = 0;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, ww - margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//        
//        if(isNegativeFound_x && !areAllNegative_x){
//            num_gap_x = (max_x - min_x) / (num_ticks - 1);
//            base_tick_x = min_x;
//            for(int i = 0; i < num_ticks; i++){
//                y_ticks[i].setPosition(margin_l + ((0 - min_x) / (max_x - min_x)) * (wl - 2 * margin_l) - (4.0 / 105) * margin_w, margin_w + i * tick_gap_y);
//            }
//        }
//        else if(isNegativeFound_x){
//            num_gap_x = (0 - min_x) / (num_ticks - 1);
//            base_tick_x = min_x;
//            for(int i = 0; i < num_ticks; i++){
//                y_ticks[i].setPosition(wl - margin_l - (4.0 / 105) * margin_w, margin_w + i * tick_gap_y);
//            }
//        }
//        else if(!isNegativeFound_x){
//            num_gap_x = (max_x - 0) / (num_ticks - 1);
//            base_tick_x = 0;
//            for(int i = 0; i < num_ticks; i++){
//                y_ticks[i].setPosition(margin_l - (4.0 / 105) * margin_w, margin_w + i * tick_gap_y);
//            }
//        }
//        
//        make_labels(num_gap_x, num_gap_y, base_tick_x, base_tick_y, tick_gap_x, tick_gap_y);
//    }
//    
//    void make_labels(double x_gap, double y_gap, double base_x, double base_y, double tick_gap_x, double tick_gap_y){
//        double yLabel_xPos = 0;
//        double xLabel_yPos = 0;
//        
//        double max_x = max(x_points, points);
//        double min_x = min(x_points, points);
//        double max_y = max(y_points, points);
//        double min_y = min(y_points, points);
//        
//        if(isNegativeFound_y && !areAllNegative_y){
//            xLabel_yPos = ww - ((0 - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w - (4.0 / 105) * margin_w;
//        }
//        else if(isNegativeFound_y){
//            xLabel_yPos = 0.75 * margin_w - (4.0 / 105) * margin_w;
//        }
//        else if(!isNegativeFound_y){
//            xLabel_yPos = ww - 0.75 * margin_w - (4.0 / 105) * margin_w;
//        }
//        
//        if(isNegativeFound_x && !areAllNegative_x){
//            yLabel_xPos = margin_l + ((0 - min_x) / (max_x - min_x)) * (wl - 2 * margin_l) - (4.0 / 105) * margin_w;
//        }
//        else if(isNegativeFound_x){
//            yLabel_xPos = wl - margin_l - (4.0 / 105) * margin_w;
//        }
//        else if(!isNegativeFound_x){
//            yLabel_xPos = margin_l - (4.0 / 105) * margin_w;
//        }
//        
//        for(int i = 0; i < num_ticks; i++){
//            double num = base_x + i * x_gap;
//            if(num == 0){
//                x_labels[i] = Text("0", font, 15);
//            }
//            else{
//                x_labels[i] = Text(to_string(num).substr(0, 5), font, 15);
//            }
//            x_labels[i].setFillColor(Color :: White);
//            x_labels[i].setPosition(margin_l + i * tick_gap_x - margin_l / 5, xLabel_yPos + 0.3 * margin_w);
//            
//            num = base_y + i * y_gap;
//            if(num == 0){
//                y_labels[i] = Text("0", font, 15);
//            }
//            else{
//                y_labels[i] = Text(to_string(num).substr(0, 5), font, 15);
//            }
//            y_labels[i].setFillColor(Color :: White);
//            y_labels[i].setPosition(yLabel_xPos - 0.6 * margin_l,ww - margin_w - i * tick_gap_y - 5);
//        }
//    }
//    
//    void set_ticks(unsigned int ticks_count){
//        num_ticks = ticks_count;
//        delete[] x_ticks;
//        delete[] y_ticks;
//        delete[] x_labels;
//        delete[] y_labels;
//        
//        x_ticks = new RectangleShape[num_ticks];
//        y_ticks = new RectangleShape[num_ticks];
//        
//        x_labels = new Text[num_ticks];
//        y_labels = new Text[num_ticks];
//    }
//    
//    void make_arrows(){
//        // 0 -> bottom
//        // 1 -> top
//        // 2 -> right
//        // 3 -> left
//        
//        double max_x = max(x_points, points);
//        double min_x = min(x_points, points);
//        double max_y = max(y_points, points);
//        double min_y = min(y_points, points);
//        
//        arrows[0].setPoint(0, Vector2f(0, 0));
//        arrows[0].setPoint(1, Vector2f(-ww / 60, -ww / 60));
//        arrows[0].setPoint(2, Vector2f(ww / 60, -ww / 60));
//        
//        arrows[1].setPoint(0, Vector2f(0, 0));
//        arrows[1].setPoint(1, Vector2f(-ww / 60, ww / 60));
//        arrows[1].setPoint(2, Vector2f(ww / 60, ww / 60));
//        
//        arrows[2].setPoint(0, Vector2f(0, 0));
//        arrows[2].setPoint(1, Vector2f(-ww / 60, ww / 60));
//        arrows[2].setPoint(2, Vector2f(-ww / 60, -ww / 60));
//        
//        arrows[3].setPoint(0, Vector2f(0, 0));
//        arrows[3].setPoint(1, Vector2f(ww / 60, ww / 60));
//        arrows[3].setPoint(2, Vector2f(ww / 60, -ww / 60));
//        
//        if(isNegativeFound_y && !areAllNegative_y){
//            arrows[2].setPosition(wl - 0.75 * margin_l + ww / 60, ww - ((0 - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w + margin_w / 30);
//            arrows[3].setPosition(0.75 * margin_l - ww / 60, ww - ((0 - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w + margin_w / 30);
//        }
//        else if(isNegativeFound_y){
//            arrows[2].setPosition(wl - 0.75 * margin_l + ww / 60, margin_w + margin_w / 30);
//            arrows[3].setPosition(0.75 * margin_l - ww / 60, margin_w + margin_w / 30);
//        }
//        else if(!isNegativeFound_y){
//            arrows[2].setPosition(wl - 0.75 * margin_l + ww / 60, ww - margin_w + margin_w / 30);
//            arrows[3].setPosition(0.75 * margin_l - ww / 60, ww - margin_w + margin_w / 30);
//        }
//        
//        if(isNegativeFound_x && !areAllNegative_x){
//            arrows[1].setPosition(margin_l + ((0 - min_x) / (max_x - min_x)) * (wl - 2 * margin_l) + margin_w / 30, 0.75 * margin_w - ww / 60);
//            arrows[0].setPosition(margin_l + ((0 - min_x) / (max_x - min_x)) * (wl - 2 * margin_l) + margin_w / 30, ww - 0.75 * margin_w + ww / 60);
//        }
//        else if(isNegativeFound_x){
//            arrows[1].setPosition(wl - margin_l + margin_w / 30, 0.75 * margin_w - ww / 60);
//            arrows[0].setPosition(wl - margin_l + margin_w / 30, ww - 0.75 * margin_w + ww / 60);
//        }
//        else if(!isNegativeFound_x){
//            arrows[1].setPosition(margin_l + margin_w / 30, 0.75 * margin_w - ww / 60);
//            arrows[0].setPosition(margin_l + margin_w / 30, ww - 0.75 * margin_w + ww / 60);
//        }
//    }
//    
//    void display(){
//        while(hm -> isOpen()){
//            Event eve;
//            while(hm -> pollEvent(eve)){
//                if(eve.type == Event :: Closed){
//                    hm -> close();
//                }
//            }
//            
//            hm -> clear();
//            hm -> draw(*lGraph);
//            hm -> draw(*x_axis);
//            hm -> draw(*y_axis);
//            
//            for(int i = 0; i < num_ticks; i++){
//                hm -> draw(x_ticks[i]);
//                hm -> draw(y_ticks[i]);
//                hm -> draw(x_labels[i]);
//                hm -> draw(y_labels[i]);
//            }
//            
//            for(int i = 0; i < 4; i++){
//                hm -> draw(arrows[i]);
//            }
//            
//            for(int i = 0; i < num_lines; i++){
//                hm -> draw(more_l[i]);
//            }
//            
//            hm -> display();
//        }
//    }
//};
//
//int main(){
//    LineGraph hm(6, 1500, 600);
//    double x[6] = {-10, 2.3, 3, 4, 5, 50};
//    double y[6] = {3, 10, 6, -10, -6, 5};
//    double l[5] = {-10, 2.3, 3, 4, 45};
//    double m[5] = {1, 2, 3, 4, 5};
//    hm.set_ticks(15);
//    hm.change_color("pink");
//    hm.make_line(x, y);
//    hm.add_line(l, m, size(l));
//    hm.change_color(1, "blue");
//    double a[3] = {1, 2, 30};
//    double b[3] = {-1, -2, -3};
//    
//    double h[4]= {0.3, -10, 50, 23};
//    double val[4] = {10, 2, 3, -1};
//    hm.add_line(a, b, size(a));
//    hm.add_line(h, val, size(h));
//    hm.change_color(2, "red");
//    hm.display();
//    return 0;
//}
