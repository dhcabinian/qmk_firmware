const rgblight_segment_t PROGMEM movement_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{41, 4, HSV_CYAN}
);
const rgblight_segment_t PROGMEM settings_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {27, 4, HSV_PURPLE}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    movement_layer,
    settings_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, 1)); // layer_state_cmp finds if layer is active, index is into my_rgb_layers
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    return state;
}
