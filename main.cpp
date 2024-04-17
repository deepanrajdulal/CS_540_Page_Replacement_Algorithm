//Required header library
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>

//Page Replacement Simulations Class
class PageReplacer {
private:
    std::vector<int> reference_string;
    int num_frames;

public:
    //Constructor for class
    PageReplacer(const std::vector<int>& ref_str, int frames) : reference_string(ref_str), num_frames(frames) {}

    //Simulating LRU Page Replacement Algorithm
    void simulateLRU() {
        std::list<int> page_table;
        int page_faults = 0;

        for (int page : reference_string) {
            auto found = std::find(page_table.begin(), page_table.end(), page);
            if (found == page_table.end()) { //Page fault detected
                ++page_faults;
                if (page_table.size() == num_frames) {
                    page_table.pop_front(); //Removing oldest used page
                }
                page_table.push_back(page); //Adding new page
                
                std::cout << "Step " << page_faults << ": Page fault (" << page << ") - Page Table: {";
                for (auto it = page_table.begin(); it != page_table.end(); ++it) {
                    std::cout << *it; //Printing page faults
                    if (std::next(it) != page_table.end()) {
                        std::cout << ", ";
                    }
                }
                std::cout << "}, Faults: " << page_faults << std::endl;
            }
        }

        std::cout << "Total Page Faults for LRU: " << page_faults << std::endl;
    }

    //Simulating Optimal Page Replacement Algorithm
    void simulateOptimal() {
        std::list<int> page_table;
        int page_faults = 0;

        for (int i = 0; i < reference_string.size(); ++i) {
            int page = reference_string[i];
            auto found = std::find(page_table.begin(), page_table.end(), page);
            if (found == page_table.end()) { //Page fault
                ++page_faults;
                if (page_table.size() == num_frames) {
                    int replace_page; //Finding the page that will not be used in future
                    int furthest_use = -1;
                    for (int frame : page_table) {
                        int next_use_index = std::distance(reference_string.begin() + i + 1, std::find(reference_string.begin() + i + 1, reference_string.end(), frame)); //Finding next index to use
                        if (next_use_index == reference_string.size()) {
                            replace_page = frame;
                            break;
                        }
                        if (next_use_index > furthest_use) {
                            furthest_use = next_use_index;
                            replace_page = frame;
                        }
                    }
                    //Removing page that wont be used in future
                    page_table.remove(replace_page);
                }
                //Adding new page
                page_table.push_back(page);
                std::cout << "Step " << page_faults << ": Page fault (" << page << ") - Page Table: {";
                for (auto it = page_table.begin(); it != page_table.end(); ++it) {
                    std::cout << *it;
                    if (std::next(it) != page_table.end()) {
                        std::cout << ", ";
                    }
                }
                std::cout << "}, Faults: " << page_faults << std::endl;
            }
        }

        std::cout << "Total Page Faults for Optimal: " << page_faults << std::endl;
    }

    //Simulating FIFO Page Replacement Algorithm
    void simulateFIFO() {
        std::list<int> page_table;
        int page_faults = 0;

        for (int page : reference_string) {
            auto found = std::find(page_table.begin(), page_table.end(), page);
            if (found == page_table.end()) { // Page fault
                ++page_faults;
                if (page_table.size() == num_frames) {
                    page_table.pop_front(); //Removing first page to enter
                }
                page_table.push_back(page);
                std::cout << "Step " << page_faults << ": Page fault (" << page << ") - Page Table: {";
                for (auto it = page_table.begin(); it != page_table.end(); ++it) {
                    std::cout << *it;
                    if (std::next(it) != page_table.end()) {
                        std::cout << ", ";
                    }
                }
                std::cout << "}, Faults: " << page_faults << std::endl;
            }
        }

        std::cout << "Total Page Faults for FIFO: " << page_faults << std::endl;
    }
};

int main() {
    std::vector<int> reference_string = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_frames = 4;
    
    PageReplacer pr(reference_string, num_frames);
    
    std::cout << "LRU Algorithm:" << std::endl;
    pr.simulateLRU();
    std::cout << std::endl;
    
    std::cout << "Optimal Algorithm:" << std::endl;
    pr.simulateOptimal();
    std::cout << std::endl;
    
    std::cout << "FIFO Algorithm:" << std::endl;
    pr.simulateFIFO();
    
    return 0;
}
