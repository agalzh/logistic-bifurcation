#include <bits/stdc++.h>
using namespace std;

int main() {
    const double r_min = 2.5;
    const double r_max = 4.0;
    const int r_steps = 12000;
    const int iterations = 2000;
    const int discard = 400;
    const double x0 = 0.5;
    const int img_w = r_steps;
    const int img_h = 4000;
    const string csv_file = "bifurcation.csv";
    const string ppm_file = "bifurcation.ppm";

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream csv(csv_file);
    if (!csv.is_open()) {
        cerr << "Error: cannot open " << csv_file << " for writing\n";
        return 1;
    }
    csv << "r,x\n";

    vector<unsigned char> img(img_w * img_h * 3, 255);

    for (int i = 0; i < r_steps; ++i) {
        double r = r_min + (r_max - r_min) * (double(i) / double(max(1, r_steps - 1)));
        double x = x0;

        for (int it = 0; it < iterations; ++it) {
            x = r * x * (1.0 - x);
            if (it >= (iterations - discard)) {
                csv << std::fixed << std::setprecision(6) << r << "," << x << "\n";
                int row = int((1.0 - x) * (img_h - 1)); 
                int col = i;
                if (row < 0) row = 0;
                if (row >= img_h) row = img_h - 1;

                size_t idx = (size_t)(row * img_w + col) * 3;
                img[idx + 0] = 0;
                img[idx + 1] = 0;
                img[idx + 2] = 0;
            }
        }

        if (i % 500 == 0) {
            cerr << "[INFO] r-step " << i << "/" << r_steps << "\n";
        }
    }

    csv.close();
    cerr << "[INFO] Saved CSV: " << csv_file << "\n";

    ofstream ppm(ppm_file, ios::binary);
    if (!ppm.is_open()) {
        cerr << "Error: cannot open " << ppm_file << " for writing\n";
        return 1;
    }
    ppm << "P6\n" << img_w << " " << img_h << "\n255\n";
    ppm.write(reinterpret_cast<char*>(img.data()), img.size());
    ppm.close();

    cerr << "[INFO] Saved image: " << ppm_file << " (" << img_w << "x" << img_h << ")\n";
    cerr << "[DONE]\n";

    return 0;
}
