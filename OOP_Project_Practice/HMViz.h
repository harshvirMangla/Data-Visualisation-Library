//  HMViz.h
//  OOP_Project_Practice
//  Created by Harshvir Mangla on 16/12/24.

//#ifndef HMVIZ_H
//#define HMVIZ_H
//
//#include<iostream>
//#include<random>
//#include<SFML/Graphics.hpp>
//#define PI 3.14159
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
//    string* classNames;
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
//        classNames = new string[num];
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
//        classNames = new string[num];
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
//    void save_classes(string* classes){
//        for(int i = 0; i < items; i++){
//            classNames[i] = classes[i];
//        }
//    }
//    
//    void make_bars(){
//        string font_path = "/System/Library/Fonts/Geneva.ttf";
//        font.loadFromFile(font_path);
//
//        for(int i = 0; i < items; i++){
//            bars[i] = RectangleShape(Vector2f(block_x / 2, heights[i] / max(heights, items) * 0.6 * ww));
//            bars[i].setPosition(i * block_x + margin_l, ww * 0.6 + margin_w - heights[i] / max(heights, items) * 0.6 * ww);
//            bars[i].setFillColor(*bar_col);
//
//            labels[i] = Text(classNames[i], font, 25);
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
//    void make_bars(double* h, string* classes){
//        save_classes(classes);
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
//    
//    friend void getData(string fileName, BarGraph& b);
//};
//
//unsigned int randomNumber(){
//    random_device hm;
//    mt19937 gen(hm());
//    uniform_int_distribution<int> distr(0, 255);
//    return distr(gen);
//}
//
//double min_hm(double* p, unsigned int items){
//    double minm = p[0];
//    for(int i = 1; i < items; i++){
//        if(p[i] < minm) minm = p[i];
//    }
//    return minm;
//}
//
//double max_hm(double* p, unsigned int items){
//    double maxm = p[0];
//    for(int i = 1; i < items; i++){
//        if(p[i] > maxm) maxm = p[i];
//    }
//    return maxm;
//}
//
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
//    bool lineMade = false;
//    double MAXX;
//    double MAXY;
//    double MINX;
//    double MINY;
//    double** more_l_points_x;
//    double** more_l_points_y;
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
//        more_l = new VertexArray[10];
//        more_l_points_x = new double*[10];
//        more_l_points_y = new double*[10];
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
//        more_l = new VertexArray[10];
//    }
//
//    void make_line(double* x, double* y){
//        if(!lineMade){
//            lineMade = true;
//            store_points(x, y);
//            more_l = new VertexArray[5];
//            double max_x = max_hm(x, points);
//            double min_x = min_hm(x, points);
//            double max_y = max_hm(y, points);
//            double min_y = min_hm(y, points);
//            
//            for(int i = 0; i < points; i++){
//                if(y[i] < 0){
//                    isNegativeFound_y = true;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(x[i] < 0){
//                    isNegativeFound_x = true;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(y[i] > 0){
//                    areAllNegative_y = false;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(x[i] > 0){
//                    areAllNegative_x = false;
//                    break;
//                }
//            }
//            
//            if(areAllNegative_x && areAllNegative_y){
//                max_x = 0;
//                max_y = 0;
//            }
//            else if(areAllNegative_x){
//                max_x = 0;
//            }
//            else if(areAllNegative_y){
//                max_y = 0;
//            }
//            else{
//                max_x = max_hm(x, points);
//                max_y = max_hm(y, points);
//            }
//            
//            if(isNegativeFound_x && isNegativeFound_y){
//                min_x = min_hm(x, points);
//                min_y = min_hm(y, points);
//            }
//            else if(isNegativeFound_x){
//                min_y = 0;
//            }
//            else if(isNegativeFound_y){
//                min_x = 0;
//            }
//            else{
//                min_x = 0;
//                min_y = 0;
//            }
//            
//            MINX = min_x;
//            MAXX = max_x;
//            MINY = min_y;
//            MAXY = max_y;
//            
//            for(int i = 0; i < points; i++){
//                (*lGraph)[i].position = Vector2f(margin_l + ((x[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((y[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//                (*lGraph)[i].color = *col;
//            }
//            
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i] = RectangleShape(Vector2f(margin_w / 15, margin_w / 7));
//                x_ticks[i].setFillColor(Color :: White);
//                y_ticks[i] = RectangleShape(Vector2f(margin_w / 7, margin_w / 15));
//                y_ticks[i].setFillColor(Color :: White);
//            }
//            
//            make_axes();
//            make_ticks();
//            make_arrows();
//        }
//        else{
//            
//            for(int i = 0; i < points; i++){
//                (*lGraph)[i].position = Vector2f(margin_l + ((x_points[i] - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), ww - ((y_points[i] - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w);
//                (*lGraph)[i].color = *col;
//            }
//            
//            for(int pos = 0; pos <= num_lines - 1; pos++){
//                for(int i = 0; i < (more_l[pos]).getVertexCount(); i++){
//                    (more_l[pos])[i].position = Vector2f(margin_l + (((more_l_points_x[pos])[i] - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), ww - (((more_l_points_y[pos])[i] - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w);
//                    (more_l[pos])[i].color = Color :: Green;
//                }
//            }
//        }
//    }
//    
//    void make_line(){
//        if(!lineMade){
//            lineMade = true;
////            more_l = new VertexArray[10];
//            double max_x = max_hm(x_points, points);
//            double min_x = min_hm(x_points, points);
//            double max_y = max_hm(y_points, points);
//            double min_y = min_hm(y_points, points);
//            
//            for(int i = 0; i < points; i++){
//                if(y_points[i] < 0){
//                    isNegativeFound_y = true;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(x_points[i] < 0){
//                    isNegativeFound_x = true;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(y_points[i] > 0){
//                    areAllNegative_y = false;
//                    break;
//                }
//            }
//            
//            for(int i = 0; i < points; i++){
//                if(x_points[i] > 0){
//                    areAllNegative_x = false;
//                    break;
//                }
//            }
//            
//            if(areAllNegative_x && areAllNegative_y){
//                max_x = 0;
//                max_y = 0;
//            }
//            else if(areAllNegative_x){
//                max_x = 0;
//            }
//            else if(areAllNegative_y){
//                max_y = 0;
//            }
//            else{
//                max_x = max_hm(x_points, points);
//                max_y = max_hm(y_points, points);
//            }
//            
//            if(isNegativeFound_x && isNegativeFound_y){
//                min_x = min_hm(x_points, points);
//                min_y = min_hm(y_points, points);
//            }
//            else if(isNegativeFound_x){
//                min_y = 0;
//            }
//            else if(isNegativeFound_y){
//                min_x = 0;
//            }
//            else{
//                min_x = 0;
//                min_y = 0;
//            }
//            
//            MINX = min_x;
//            MAXX = max_x;
//            MINY = min_y;
//            MAXY = max_y;
//            
//            for(int i = 0; i < points; i++){
//                (*lGraph)[i].position = Vector2f(margin_l + ((x_points[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((y_points[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//                (*lGraph)[i].color = *col;
//            }
//            
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i] = RectangleShape(Vector2f(margin_w / 15, margin_w / 7));
//                x_ticks[i].setFillColor(Color :: White);
//                y_ticks[i] = RectangleShape(Vector2f(margin_w / 7, margin_w / 15));
//                y_ticks[i].setFillColor(Color :: White);
//            }
//            
//            make_axes();
//            make_ticks();
//            make_arrows();
//        }
//        else{
//            reset_axes();
//            for(int i = 0; i < points; i++){
//                (*lGraph)[i].position = Vector2f(margin_l + ((x_points[i] - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), ww - ((y_points[i] - MINY) / (MAXY - MINY)) * (ww - 2 * margin_w) - margin_w);
//                (*lGraph)[i].color = *col;
//            }
//            for(int pos = 0; pos <= num_lines - 1; pos++){
//                unsigned int r = randomNumber();
//                unsigned int g = randomNumber();
//                unsigned int b = randomNumber();
//                for(int i = 0; i < (more_l[pos]).getVertexCount(); i++){
//                    (more_l[pos])[i].position = Vector2f(margin_l + (((more_l_points_x[pos])[i] - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), ww - (((more_l_points_y[pos])[i] - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w);
//                    (more_l[pos])[i].color = Color(r, g, b);
//                }
//            }
//            make_ticks();
//            make_arrows();
//        }
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
//    void add_line(double* l, double* m, unsigned int size);
//    
//    void add_line(string fileName);
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
////        double max_x = max_hm(x_points, points);
////        double min_x = min_hm(x_points, points);
////        double max_y = max_hm(y_points, points);
////        double min_y = min_hm(y_points, points);
//
//        x_axis = new RectangleShape(Vector2f(wl - 1.5 * margin_l, margin_w / 15));
//        x_axis -> setFillColor(Color :: White);
//
//        y_axis = new RectangleShape(Vector2f(margin_w / 15, ww - 1.5 * margin_w));
//        y_axis -> setFillColor(Color :: White);
//
//        if(isNegativeFound_y && !areAllNegative_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - ((0 - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w);
//        }
//        else if(isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, margin_w);
//        }
//        else if(!isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - margin_w);
//        }
//
//        if(isNegativeFound_x && !areAllNegative_x){
//            y_axis -> setPosition(margin_l + ((0 - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), 0.75 * margin_w);
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
//    void reset_axes(){
//        if(isNegativeFound_y && !areAllNegative_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - ((0 - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w);
//        }
//        else if(isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, margin_w);
//        }
//        else if(!isNegativeFound_y){
//            x_axis -> setPosition(0.75 * margin_l, ww - margin_w);
//        }
//
//        if(isNegativeFound_x && !areAllNegative_x){
//            cout << "Occurring" << endl;
//            cout << margin_l + ((0 - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l) << endl;
//            y_axis -> setPosition(margin_l + ((0 - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l), 0.75 * margin_w);
//        }
//        else if(isNegativeFound_x){
//            y_axis -> setPosition(wl - margin_l, 0.75 * margin_w);
//        }
//        else if(!isNegativeFound_x){
//            y_axis -> setPosition(margin_l, 0.75 * margin_w);
//        }
//    }
//
//    void make_ticks(){
//        string font_path = "/System/Library/Fonts/Geneva.ttf";
//        font.loadFromFile(font_path);
//
////        double max_x = max_hm(x_points, points);
////        double min_x = min_hm(x_points, points);
////        double max_y = max_hm(y_points, points);
////        double min_y = min_hm(y_points, points);
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
//            num_gap_y = (MAXY - MINY) / (num_ticks - 1);
//            base_tick_y = MINY;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, ww - ((0 - MINY) / (MAXY - MINY) * (ww - 2 * margin_w)) - margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//        else if(isNegativeFound_y){
//            num_gap_y = (0 - MINY) / (num_ticks - 1);
//            base_tick_y = MINY;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//        else if(!isNegativeFound_y){
//            num_gap_y = (MAXY - 0) / (num_ticks - 1);
//            base_tick_y = 0;
//            for(int i = 0; i < num_ticks; i++){
//                x_ticks[i].setPosition(margin_l + i * tick_gap_x, ww - margin_w - (4.0 / 105) * margin_w);
//            }
//        }
//
//        if(isNegativeFound_x && !areAllNegative_x){
//            num_gap_x = (MAXX - MINX) / (num_ticks - 1);
//            base_tick_x = MINX;
//            for(int i = 0; i < num_ticks; i++){
//                y_ticks[i].setPosition(margin_l + ((0 - MINX) / (MAXX - MINX)) * (wl - 2 * margin_l) - (4.0 / 105) * margin_w, margin_w + i * tick_gap_y);
//            }
//        }
//        else if(isNegativeFound_x){
//            num_gap_x = (0 - MINX) / (num_ticks - 1);
//            base_tick_x = MINX;
//            for(int i = 0; i < num_ticks; i++){
//                y_ticks[i].setPosition(wl - margin_l - (4.0 / 105) * margin_w, margin_w + i * tick_gap_y);
//            }
//        }
//        else if(!isNegativeFound_x){
//            num_gap_x = (MAXX - 0) / (num_ticks - 1);
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
//        cout << "Base tick: " << base_x << endl;
//
//        double max_x = MAXX;
//        double min_x = MINX;
//        double max_y = MAXY;
//        double min_y = MINY;
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
//        double max_x = MAXX;
//        double min_x = MINX;
//        double max_y = MAXY;
//        double min_y = MINY;
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
////            cout << "Displaying" << endl;
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
//
//    friend void getData(string fileName, LineGraph& l);
//};
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
//    void make_pie(){
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
//            double angle = values[i] / total;
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
//    
//    friend void getData(string fileName, PieChart& p);
//};
//
////double min(double* p, unsigned int items){
////    double minm = p[0];
////    for(int i = 1; i < items; i++){
////        if(p[i] < minm) minm = p[i];
////    }
////    return minm;
////}
////
////double max(double* p, unsigned int items){
////    double maxm = p[0];
////    for(int i = 1; i < items; i++){
////        if(p[i] > maxm) maxm = p[i];
////    }
////    return maxm;
////}
//
//class ScatterPlot{
//private:
//    RenderWindow* hm;
//    double wl = 1000;
//    double ww = 800;
//    unsigned int points;
//    unsigned int margin_l = 0.08 * wl;
//    unsigned int margin_w = 0.08 * ww;
//    double* x_points;
//    double* y_points;
//    CircleShape* circles;
//    Font font;
//    Color* col;
//    float radius = 5;
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
//
//public:
//    ScatterPlot(unsigned int num){
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Line Graph");
//        points = num;
//        x_points = new double[points];
//        y_points = new double[points];
//        circles = new CircleShape[points];
//        col = new Color(15, 255, 79);
//        x_ticks = new RectangleShape[num_ticks];
//        y_ticks = new RectangleShape[num_ticks];
//        x_labels = new Text[num_ticks];
//        y_labels = new Text[num_ticks];
//        arrows = new ConvexShape[4];
//    }
//
//    ScatterPlot(unsigned int num, double pix_l, double pix_w, unsigned int ticks_count = 8){
//        wl = pix_l;
//        ww = pix_w;
//        hm = new RenderWindow(VideoMode(wl, ww), "Harshvir's Line Graph");
//        points = num;
//        x_points = new double[points];
//        y_points = new double[points];
//        circles = new CircleShape[points];
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
//    void make_points(double* x, double* y){
//        store_points(x, y);
//        double max_x = max_hm(x, points);
//        double min_x = min_hm(x, points);
//        double max_y = max_hm(y, points);
//        double min_y = min_hm(y, points);
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
//            min_x = min_hm(x, points);
//            min_y = min_hm(y, points);
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
//            circles[i] = CircleShape(radius);
//            Vector2f pos = Vector2f(margin_l + ((x[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((y[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//            circles[i].setPosition(pos.x, pos.y);
//            circles[i].setFillColor(*col);
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
//            circles[i].setFillColor(*col);
//        }
//    }
//
//    void make_axes(){
//        double max_x = max_hm(x_points, points);
//        double min_x = min_hm(x_points, points);
//        double max_y = max_hm(y_points, points);
//        double min_y = min_hm(y_points, points);
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
//        double max_x = max_hm(x_points, points);
//        double min_x = min_hm(x_points, points);
//        double max_y = max_hm(y_points, points);
//        double min_y = min_hm(y_points, points);
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
//        double max_x = max_hm(x_points, points);
//        double min_x = min_hm(x_points, points);
//        double max_y = max_hm(y_points, points);
//        double min_y = min_hm(y_points, points);
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
//        double max_x = max_hm(x_points, points);
//        double min_x = min_hm(x_points, points);
//        double max_y = max_hm(y_points, points);
//        double min_y = min_hm(y_points, points);
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
//
//            for(int i = 0; i < points; i++){
//                hm -> draw(circles[i]);
//            }
//
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
//            hm -> display();
//        }
//    }
//};
//
//void getData(string fileName, PieChart& p){
//    fstream file(fileName);
//    if(!file){
//        cerr << "File could not be opened." << endl;
//    }
//    string line;
//    unsigned int data_points = 0;
//    while(getline(file, line)){
//        data_points++;
//    }
//    p.number = data_points;
//    delete[] p.values;
//    delete[] p.classes;
//    delete p.center;
//    delete[] p.sectors;
//    delete[] p.colors;
//    delete[] p.labels;
//    p.values = new double[p.number];
//    p.classes = new string[p.number];
//    p.center = new Vector2f(p.wl / 2, p.ww / 2);
//    p.radius = (p.wl < p.ww)? 0.3 * p.wl : 0.3 * p.ww;
//    p.sectors = new ConvexShape*[p.number];
//    p.colors = new Color*[5];
//    p.labels = new Text[p.number];
//    
//    file.clear();
//    file.seekg(0, ios :: beg);
//    int index_res = 0;
//    string name;
//    double value;
//
//    while(file.eof() == 0 && file.good()){
//        file >> name >> value;
////        cout << name << endl;
////        cout << value << endl;
//        p.values[index_res] = value;
//        p.classes[index_res] = name;
//        index_res++;
//    }
//}
//
//void getData(string fileName, BarGraph& b){
//    fstream file(fileName);
//    
//    if(!file){
//        cerr << "File could not be opened." << endl;
//    }
//    string line;
//    unsigned int data_points = 0;
//    
//    while(getline(file, line)){
//        data_points++;
//    }
//    
//    unsigned int num = data_points;
//    delete[] b.heights;
//    delete[] b.bars;
//    delete[] b.classNames;
//    delete[] b.labels;
//    
//    b.items = num;
//    b.heights = new double[b.items];
//    b.bars = new RectangleShape[num];
//    b.labels = new Text[num];
//    b.classNames = new string[num];
//    
//    file.clear();
//    file.seekg(0, ios :: beg);
//    int index_res = 0;
//    string name;
//    double value;
//
//    while(file.eof() == 0 && file.good()){
//        file >> name >> value;
//        b.heights[index_res] = value;
//        b.classNames[index_res] = name;
//        index_res++;
//    }
//}
//
//void LineGraph :: add_line(double* l, double* m, unsigned int size){
//    more_l[num_lines++] = VertexArray(LineStrip, size);
//    double max_x = max_hm(x_points, points);
//    double min_x = min_hm(x_points, points);
//    double max_y = max_hm(y_points, points);
//    double min_y = min_hm(y_points, points);
//    
//    bool areAllNegx_, isNegFoundx_, areAllNegy_, isNegFoundy_;
//    areAllNegx_ = true;
//    areAllNegy_ = true;
//    isNegFoundx_ = false;
//    isNegFoundy_ = false;
//    for(int i = 0; i < size; i++){
//        if(l[i] < 0) isNegFoundx_ = true;
//        else areAllNegx_ = false;
//        
//        if(m[i] < 0) isNegFoundy_ = true;
//        else areAllNegy_ = false;
//    }
//    
//    isNegativeFound_x = isNegativeFound_x || isNegFoundx_;
//    isNegativeFound_y = isNegativeFound_y || isNegFoundy_;
//    areAllNegative_x = areAllNegative_x && areAllNegx_;
//    areAllNegative_y = areAllNegative_y && areAllNegy_;
//    
//    double max_x_dash = max_hm(l, size);
//    double min_x_dash = min_hm(l, size);
//    double max_y_dash = max_hm(m, size);
//    double min_y_dash = min_hm(m, size);
//    
//    bool changed = false;
//    
//    if(max_x < max_x_dash){
//        max_x = max_x_dash;
//        changed = true;
//    }
//    if(min_x > min_x_dash){
//        min_x = min_x_dash;
//        changed = true;
//    }
//    if(max_y < max_y_dash){
//        max_y = max_y_dash;
//        changed = true;
//    }
//    if(min_y > min_y_dash){
//        min_y = min_y_dash;
//        changed = true;
//    }
//
//    if(areAllNegative_x && areAllNegative_y){
//        max_x = 0;
//        max_y = 0;
//    }
//    else if(areAllNegative_x){
//        max_x = 0;
//    }
//    else if(areAllNegative_y){
//        max_y = 0;
//    }
//    else{
//        max_x = max_hm(x_points, points);
//        max_y = max_hm(y_points, points);
//    }
//
//    if(isNegativeFound_x && isNegativeFound_y){
//        min_x = min_hm(x_points, points);
//        min_y = min_hm(y_points, points);
//    }
//    else if(isNegativeFound_x){
//        min_y = 0;
//    }
//    else if(isNegativeFound_y){
//        min_x = 0;
//    }
//    else{
//        min_x = 0;
//        min_y = 0;
//    }
//    
//    if(changed){
//        MINX = min_x;
//        MAXX = max_x;
//        MINY = min_y;
//        MAXY = max_y;
//    }
//    
//    more_l_points_x[num_lines - 1] = new double[size];
//    more_l_points_y[num_lines - 1] = new double[size];
//    
//    for(int i = 0; i < size; i++){
//        more_l_points_x[num_lines - 1][i] = l[i];
//        more_l_points_y[num_lines - 1][i] = m[i];
//        (more_l[num_lines - 1])[i].position = Vector2f(margin_l + ((l[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((m[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//        (more_l[num_lines - 1])[i].color = Color :: Green;
//    }
//}
//
//void getData(string fileName, LineGraph& l){
//    fstream file(fileName);
//    
//    if(!file){
//        cerr << "File could not be opened." << endl;
//    }
//    string line;
//    unsigned int data_points = 0;
//    
//    while(getline(file, line)){
//        data_points++;
//    }
//    
//    l.points = data_points;
//    delete[] l.x_points;
//    delete[] l.y_points;
//    delete l.lGraph;
//    
//    l.x_points = new double[l.points];
//    l.y_points = new double[l.points];
//    l.lGraph = new VertexArray(LinesStrip, l.points);
//    
//    file.clear();
//    file.seekg(0, ios :: beg);
//    int index_res = 0;
//    
//    double x;
//    double y;
//    
//    while(file.eof() == 0 && file.good()){
//        file >> x >> y;
//        l.x_points[index_res] = x;
//        l.y_points[index_res] = y;
//        index_res++;
//    }
//}
//
//void LineGraph :: add_line(string fileName){
//    fstream file(fileName);
//    
//    if(!file){
//        cerr << "File could not be opened." << endl;
//    }
//    
//    string line;
//    unsigned int data_points = 0;
//    
//    while(getline(file, line)){
//        data_points++;
//    }
//    
//    file.clear();
//    file.seekg(0, ios :: beg);
//    
////    cout << data_points << endl;
//    
//    double* l = new double[data_points];
//    double* m = new double[data_points];
//    unsigned int index_res = 0;
//    
//    double num;
//    
//    while(file.eof() == 0 && file.good()){
//        file >> num;
//        l[index_res] = num;
//        file >> num;
//        m[index_res] = num;
////        file >> l[index_res] >> m[index_res];
//        cout << l[index_res] << m[index_res] << endl;
//        index_res++;
//    }
//    
//    more_l[num_lines++] = VertexArray(LineStrip, data_points);
//    double max_x = MAXX;
//    double min_x = MINX;
//    double max_y = MAXY;
//    double min_y = MINY;
//    
//    bool areAllNegx_, isNegFoundx_, areAllNegy_, isNegFoundy_;
//    areAllNegx_ = true;
//    areAllNegy_ = true;
//    isNegFoundx_ = false;
//    isNegFoundy_ = false;
//    for(int i = 0; i < data_points; i++){
//        if(l[i] < 0) isNegFoundx_ = true;
//        else areAllNegx_ = false;
//        
//        if(m[i] < 0) isNegFoundy_ = true;
//        else areAllNegy_ = false;
//    }
//    
//    cout << "Print it" << endl;
//    cout << isNegativeFound_x << endl;
//    cout << isNegFoundx_ << endl;
//    cout << areAllNegative_x << endl;
//    cout << areAllNegx_ << endl;
//    
//    isNegativeFound_x = isNegativeFound_x || isNegFoundx_;
//    isNegativeFound_y = isNegativeFound_y || isNegFoundy_;
//    areAllNegative_x = areAllNegative_x && areAllNegx_;
//    areAllNegative_y = areAllNegative_y && areAllNegy_;
//    
//    cout << areAllNegative_x << endl;
//    
//    double max_x_dash = max_hm(l, data_points);
//    double min_x_dash = min_hm(l, data_points);
//    double max_y_dash = max_hm(m, data_points);
//    double min_y_dash = min_hm(m, data_points);
//    
//    bool changed = false;
//    
//    cout << "Help: " << max_x_dash << endl;
//    
//    if(max_x < max_x_dash){
//        MAXX = max_x_dash;
//        max_x = max_x_dash;
//        changed = true;
//    }
//    if(min_x > min_x_dash){
//        MINX = min_x_dash;
//        min_x = MINX;
//        changed = true;
//    }
//    if(max_y < max_y_dash){
//        MAXY = max_y_dash;
//        max_y = MAXY;
//        changed = true;
//    }
//    if(min_y > min_y_dash){
//        MINY = min_y_dash;
//        min_y = MINY;
//        changed = true;
//    }
//    
////    if(areAllNegative_x && areAllNegative_y){
////        max_x = 0;
////        max_y = 0;
////    }
////    else if(areAllNegative_x){
////        max_x = 0;
////    }
////    else if(areAllNegative_y){
////        max_y = 0;
////    }
////    else{
//////        max_x = max_hm(x_points, points);
//////        max_y = max_hm(y_points, points);
////    }
////    
////    if(isNegativeFound_x && isNegativeFound_y){
////        
//////        min_x = min_hm(x_points, points);
//////        min_y = min_hm(y_points, points);
////    }
////    else if(isNegativeFound_x){
////        min_y = 0;
////    }
////    else if(isNegativeFound_y){
////        min_x = 0;
////    }
////    else{
////        min_x = 0;
////        min_y = 0;
////    }
//    
//    if(areAllNegative_x && areAllNegative_y){
//        max_x = 0;
//        max_y = 0;
//    }
//    else if(areAllNegative_x){
//        max_x = 0;
//    }
//    else if(areAllNegative_y){
//        max_y = 0;
//    }
//    else{
////        max_x = max_hm(x_points, points);
////        max_y = max_hm(y_points, points);
//    }
//    
//    if(isNegativeFound_x && isNegativeFound_y){
////        min_x = min_hm(x_points, points);
////        min_y = min_hm(y_points, points);
//    }
//    else if(isNegativeFound_x){
//        min_y = 0;
//    }
//    else if(isNegativeFound_y){
//        min_x = 0;
//    }
//    else{
//        min_x = 0;
//        min_y = 0;
//    }
//    
//    if(changed){
//        
//        MINX = min_x;
//        MAXX = max_x;
//        MINY = min_y;
//        MAXY = max_y;
//        
//        cout << "MAXX" << MAXX << endl;
//        cout << "MINX" << MINX << endl;
//        cout << "MAXY" << MAXY << endl;
//        cout << "MINY" << MINY << endl;
//        
//    }
//    
//    more_l_points_x[num_lines - 1] = new double[data_points];
//    more_l_points_y[num_lines - 1] = new double[data_points];
//    
//    for(int i = 0; i < data_points; i++){
////        cout << l[i] << m[i] << endl;
//        more_l_points_x[num_lines - 1][i] = l[i];
//        more_l_points_y[num_lines - 1][i] = m[i];
//        (more_l[num_lines - 1])[i].position = Vector2f(margin_l + ((l[i] - min_x) / (max_x - min_x)) * (wl - 2 * margin_l), ww - ((m[i] - min_y) / (max_y - min_y) * (ww - 2 * margin_w)) - margin_w);
//    }
//}
//
//#endif
//
