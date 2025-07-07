# HMViz - Data Visualization Library

Hey there! Welcome to HMViz, a C++ data visualization library I (Harshvir Mangla) put together to make creating bar graphs, line graphs, pie charts, and scatter plots as smooth as possible. It uses SFML to render everything, and it’s designed to be intuitive whether you’re analyzing data or just messing around with cool visuals.

## What’s HMViz All About?

HMViz is my take on making data visualization fun and flexible. It’s got everything you need to turn raw numbers into clean, interactive charts. Whether you’re a student, a data enthusiast, or just curious, this library should make your life easier.

## What Can It Do?

- **Bar Graphs**: Show off categorical data with customizable colors and labels. Click a bar to highlight it!
- **Line Graphs**: Plot continuous data, add multiple lines, and handle negative values like a champ.
- **Pie Charts**: Display proportions with clickable sectors that highlight when you interact with them.
- **Scatter Plots**: Visualize data points in 2D with dynamic axes that adjust for positive or negative values.
- **File Input**: Pull data straight from text files for quick setup.
- **Customizable**: Change colors, tweak tick marks, or resize the window to fit your vibe.
- **Smart Axes**: Automatically scales to fit your data, even if it’s got negative values.

## Getting Started

Here’s what you’ll need to get HMViz up and running:

- **C++ Compiler**: Something that supports C++17 (like g++ or clang++).
- **SFML**: You’ll need SFML (version 2.5 or higher) for the graphics.
  - macOS: `brew install sfml`
  - Ubuntu: `sudo apt-get install libsfml-dev`
  - Windows: Check out the [SFML setup guide](https://www.sfml-dev.org/tutorials/2.5/start-vc.php).
- **Font**: I used Geneva font (macOS default). If you’re on another system, you might need to swap the font path in the code.

## Installation

1. **Grab the Code**:
   ```bash
   git clone https://github.com/harshvir/HMViz.git
   cd HMViz
   ```

2. **Set Up SFML**:
   Install SFML for your system and make sure it’s linked when you compile.

3. **Compile**:
   Here’s an example with g++:
   ```bash
   g++ -c main.cpp -I/path/to/sfml/include
   g++ main.o -o HMViz -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. **Run It**:
   ```bash
   ./HMViz
   ```

## How to Use It

HMViz has four main classes: `BarGraph`, `LineGraph`, `PieChart`, and `ScatterPlot`. Here’s a quick rundown on how to use them.

### Bar Graph
Make a bar graph with some data and labels:
```cpp
#include "HMViz.h"

int main() {
    BarGraph b(5);
    double heights[] = {10, 20, 15, 30, 25};
    string classes[] = {"A", "B", "C", "D", "E"};
    b.make_bars(heights, classes);
    b.display();
    return 0;
}
```

### Line Graph
Plot a line with x and y points:
```cpp
#include "HMViz.h"

int main() {
    LineGraph l(5);
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {10, 20, 25, 20, 10};
    l.make_line(x, y);
    l.display();
    return 0;
}
```

### Pie Chart
Show proportions with a pie chart:
```cpp
#include "HMViz.h"

int main() {
    PieChart p(4);
    double values[] = {25, 35, 20, 20};
    string classes[] = {"Apples", "Bananas", "Oranges", "Pears"};
    p.make_pie(values, classes);
    p.display();
    return 0;
}
```

### Scatter Plot
Plot points in 2D:
```cpp
#include "HMViz.h"

int main() {
    ScatterPlot s(5);
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {10, 20, 25, 20, 10};
    s.make_points(x, y);
    s.display();
    return 0;
}
```

### Loading Data from Files
You can load data from a text file like this:
```cpp
#include "HMViz.h"

int main() {
    BarGraph b(0); // Size set by file
    getData("data.txt", b);
    b.make_bars();
    b.display();
    return 0;
}
```

**Sample File Format** (data.txt):
```
Apples 50
Bananas 30
Oranges 20
```

For `LineGraph` or `ScatterPlot`:
```
1 10
2 20
3 15
```

## Tweaking Things

- **Colors**: Switch up colors with `change_color("color")`. Try `blue`, `green`, `red`, `brown`, or `pink`.
- **Ticks**: Set the number of axis ticks with `set_ticks(num)`.
- **Window Size**: Pass custom dimensions to the constructor, like `BarGraph(num, width, height)`.

## Things to Watch Out For

- **Font Path**: The code assumes `/System/Library/Fonts/Geneva.ttf`. Change it if you’re not on macOS.
- **File Input**: Make sure your data files are formatted correctly, or you might hit errors.
- **Negative Values**: `LineGraph` and `ScatterPlot` handle negatives, but `BarGraph` and `PieChart` expect non-negative data.

## Want to Contribute?

I’d love to see what you can add to HMViz! Feel free to open a pull request or report issues on the GitHub repo.

## License

This project is under the MIT License. Check the `LICENSE` file for more details.

## Shoutouts

Big thanks to SFML for making the graphics side of things a breeze. This project started as a way for me to practice OOP and data visualization, and I’m stoked to share it with you!
