# Logistic Map — Bifurcation Diagram (C++ Simulation)

This project is a small exploration of the logistic map and its bifurcation behaviour.  
I used C++ to simulate the system, iterate over a range of *r* values, and generate the bifurcation diagram.

The logistic map is defined by the iterative equation:

x_{n+1} = r * x_n * (1 - x_n)


This simple recurrence moves from stable behaviour → oscillations → period-doubling → chaos.  
Inside the chaotic region, you can also see periodic windows, band-merging points, and regions where the system becomes stable again.

---

## Output Files

All generated files (PNG, PPM, CSV) have been included as a compressed archive:

- **outputs.zip**

Inside the ZIP:
- `bifurcation.png` — final image  
- `bifurcation.ppm` — raw PPM output  
- `bifurcation.csv` — (r, x) data from the simulation  

The PNG is the main visualization.  
The raw files are included for completeness.
**Note:** A copy of the bifurcation PNG is kept in the `out/` folder for easy access.

---

## Build & Run

### Compile (requires g++)
g++ -O2 logistic_bifurcation.cpp -o logistic_bifurcation

### Run
./logistic_bifurcation

This will generate fresh versions of:
- `bifurcation.ppm`  
- `bifurcation.csv`

You can convert the PPM to PNG using ImageMagick:
magick bifurcation.ppm -resize 4000x2500 -gamma 0.9 -sharpen 0x1 bifurcation.png


---

## What to Look For in the Diagram

- A long stable region before chaos begins  
- Period-doubling leading into chaos  
- Periodic windows (e.g., the period-3 window)  
- Chaotic bands merging at specific r-values (band-merging points)  
- Stable regions appearing inside chaos  

These patterns also appear in real systems like population models, stock markets, control loops, neural networks, and weather models.

---

## Notes

- This project was done while exploring dynamical systems out of personal curiosity.
- The code is kept simple on purpose for clarity.
- The ZIP file contains all the outputs so the simulation does not need to be rerun.

---

