#include "ofPalette.h"

ofPalette ofPalette::getLerped(ofPalette other, float alpha) {
    assert(colors.size() == other.colors.size());
    
    ofPalette result;
    for (int i = 0; i < colors.size(); i++) {
        result.colors.emplace_back(colors[i].getLerped(other.colors[i], alpha));
    }
    return result;
}
