import xml.etree.ElementTree as ET

W, H = 12, 4

layers = {
    "base-layer": [
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None, None, ",", None, None, None, None, None, None],
        [None, None, None, "-", None, None, ".", None, None, None, None, None],
        [None, None, None, None],
    ],
    "base-shift-layer": [
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, "Q", "C", "O", "P", "W", "J", "M", "D", "★", "F", None],
        [None, "A", "S", "E", "N", ";", "L", "R", "T", "I", "U", None],
        [None, "Z", "X", "?", "V", "B", ":", "H", "G", "Y", "K", None],
        [None, None, None, None],
    ],
    "dk-layer": [
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, "â", "ç", None, "ô", None, None, None, None, None, None, None],
        [None, "à", "é", "è", "ê", None, None, None, "î", "û", "ù", None],
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None],
    ],
    "symb-layer": [
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, "@", "<", ">", "$", "%", "^", "&", "*", "'", "`", None],
        [None, "{", "(", ")", "}", "=", "\\", "+", "-", "/", "\"", None],
        [None, "~", "[", "]", "_", "#", "|", "!", ";", ":", "?", None],
        [None, None, None, None],
    ],
    "nav-layer": [
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None, None, None, None, None],
        [None, None, None, None],
    ],
}

STYLE = """
/* Box and text style */
rect {
    fill: #f8f8f8;
    stroke: #666;
    stroke-width: .5px;
}
text {
    fill: #999;
    font: normal 20px sans-serif;
    text-align: center;
    text-anchor: middle;
}

.deadKey {
  fill: red;
  font-size: 14px;
}

.dualKey { fill: #ddd; transform: translateY(26px); }

.shortcut { font-size: smaller; }
.layerMod { font-weight: bold; font-size: 14px; }
.layerMod, .colorMod { fill: #333; }

.dk-layer { fill: green; }
.symb-layer { fill: blue; font-weight: normal; }
.nav-layer { font-weight: bold; fill: #e83; }

.colorSym { fill: blue; }
.colorNav { fill: #e83; }

@media (prefers-color-scheme: dark) {
    text                 { fill: #888; }
    rect                 { fill: #444; }
    .dk-layer, .colorSym { fill: #6d6; }
    .symb-layer, .colorSym { fill: #99f; }
    .nav-layer, .colorNav { fill: #e83; }

    .dualKey             { fill: #666; }
    .layerMod, .colorMod { fill: #eee; }
}


/* Key position */
#row-1 { transform: translate(64px,  64px); }
#row-2 { transform: translate(64px, 124px); }
#row-3 { transform: translate(64px, 184px); }
#row-4 { transform: translate(64px, 244px); }
#row-5 { transform: translate(64px, 304px); }
.left   { transform: translate(-15px, 0); }
.right  { transform: translate(+15px, 0); }

/* Layer transformation */

/* --- BASE layer --- */
.base-shift-layer {transform: translate(12.8px, 20.6px)}
.base-layer {transform: translate(12.8px, 43.4px)}
.dk-layer {transform: translate(38px, 43.4px); opacity:0.5;}
.symb-layer {display: none;}

/* --- 1DK layer --- */
.dk .base-shift-layer {transform: translate(12.8px, 20.6px); opacity: 0.5;}
.dk .base-layer {transform: translate(12.8px, 43.4px); opacity: 0.5;}
.dk .dk-layer {transform: translate(38px, 43.4px); opacity: 1;}
.dk .symb-layer {display: none;}

/* --- symb layer --- */
.symb .base-shift-layer {transform: translate(12.8px, 20.6px); opacity: 0.5;}
.symb .base-layer {transform: translate(12.8px, 43.4px); opacity: 0.5;}
.symb .dk-layer {display: none;}
.symb .symb-layer {transform: translate(38px, 43.4px); opacity: 1;}

.empty .base-layer, .empty .base-shift-layer, .empty .dk-layer, .empty .symb-layer{display: none;}

"""

root = ET.Element(
    "svg", {"xmlns": "http://www.w3.org/2000/svg", "viewBox": "90 60 840 330"}
)
style_element = ET.SubElement(root, "style")
style_element.text = STYLE

for j in range(H + 1):

    row_element = ET.SubElement(root, "g", {"id": f"row-{j+1}"})
    left_element = ET.SubElement(row_element, "g", {"class": "left"})
    right_element = ET.SubElement(row_element, "g", {"class": "right"})

    is_thumb_row = j == H
    L = 4 if is_thumb_row else W

    for i in range(L):
        element = left_element if i < L / 2 else right_element
        key_translation = 210 + i * 120 if is_thumb_row else 90 + i * 60

        key_element = ET.SubElement(
            element, "g", {"transform": f"translate({key_translation})"}
        )
        ET.SubElement(
            key_element,
            "rect",
            {"width": "112" if is_thumb_row else "52", "height": "52", "rx": "5", "ry": "5"},
        )
        for layer_name, values in layers.items():

            sub_element = ET.SubElement(key_element, "text", {"class": layer_name})
            if (v := values[j][i]) is not None:
                sub_element.text = v
                if v == "★":
                    sub_element.set("class", f"{layer_name} deadKey")

tree = ET.ElementTree(root)
ET.indent(tree)
tree.write("test.svg", short_empty_elements=False)
