// Convert the HSV fields at slots 3..5 into RGB slots 0..2.
// Behavior candidate transcribed from FUN_00428e50.
extern "C" void __cdecl FUN_00428e50(int *colour)
{
    int hue = colour[3];
    if (hue < 0) hue += 360;
    else if (hue > 359) hue -= 360;
    int saturation = colour[4];
    if (saturation < 0) saturation = 0;
    else if (saturation > 254) saturation = 255;
    int value = colour[5];
    if (value < 0) value = 0;
    else if (value > 254) value = 255;

    int position = ((hue * 255) % 15300) / 60;
    int floor = ((255 - saturation) * value) / 255;
    int falling = ((saturation * position) / -255 + 255) * value / 255;
    int rising = (((position - 255) * saturation) / 255 + 255) * value / 255;
    int red = falling;
    int green = falling;
    int blue = falling;
    switch ((hue * 255) / 15300) {
    case 0: red = value; green = rising; blue = floor; break;
    case 1: green = value; blue = floor; break;
    case 2: red = floor; green = value; blue = rising; break;
    case 3: red = floor; blue = value; break;
    case 4: red = rising; green = floor; blue = value; break;
    case 5: red = value; green = floor; break;
    }
    colour[0] = red;
    colour[1] = green;
    colour[2] = blue;
}
