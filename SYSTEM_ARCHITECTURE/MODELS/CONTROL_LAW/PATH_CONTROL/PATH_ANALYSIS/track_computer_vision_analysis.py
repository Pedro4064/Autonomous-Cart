import cv2
import numpy as np
from scipy.io import savemat
import matplotlib.pyplot as plt


# Step 1: Load and preprocess the image
img = cv2.imread('circuit.jfif')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 0)
_, binary = cv2.threshold(blurred, 128, 255, cv2.THRESH_BINARY)
binary_map = (binary == 255).astype(np.uint8)

# Step 2: Real-world dimensions in mm
real_world_width = 1900  # mm
real_world_height = 3840  # mm

# Step 3: Find contours on the original binary map
contours, _ = cv2.findContours(binary_map, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Step 4: Convert real-world dimensions (10 mm, 20 mm) to pixels based on the original map's scaling
scaling_factor_x = binary_map.shape[1] / real_world_width
scaling_factor_y = binary_map.shape[0] / real_world_height
border_10mm_x = int(500 * scaling_factor_x)
border_10mm_y = int(500 * scaling_factor_y)
border_20mm_x = int(40 * scaling_factor_x)
border_20mm_y = int(40 * scaling_factor_y)

# Step 5: Add borders on the original binary map
border_img = np.zeros((binary_map.shape[0], binary_map.shape[1], 3), dtype=np.uint8)

# Add cost layers from borders
color_gradient = np.linspace(0, 255, 86)
for layer_index, layer_thickness in enumerate(range(300, 40, -10)):
    border_thickness = int(layer_thickness * scaling_factor_x)
    border = cv2.drawContours(np.zeros_like(binary_map), contours, -1, 255, thickness=border_thickness)
    border_img[border == 255] = [0, 0, color_gradient[layer_index]]

# Add the path back in white
border_img[binary_map == 1] = [255, 255, 255]

# Step 6: Scale the image to real-world dimensions
scaled_img = cv2.resize(border_img, (int(real_world_width), int(real_world_height)), interpolation=cv2.INTER_LINEAR)
scaled_binary_map = cv2.resize(binary_map, (int(real_world_width), int(real_world_height)), interpolation=cv2.INTER_LINEAR)

# Step 7: Show the scaled image with borders
plt.imshow(cv2.cvtColor(scaled_img, cv2.COLOR_BGR2RGB))
plt.title('Scaled 2D Map with Borders (1mm per Pixel)')
plt.show()

savemat('track_map.mat', {'cost_map': scaled_img, 'track_map': scaled_binary_map})

# Output scaled map dimensions and pixel-per-mm ratios
print(f"Scaled map size: {scaled_img.shape[1]} pixels (width) x {scaled_img.shape[0]} pixels (height)")
print(f"Pixel per mm (width): {scaled_img.shape[1] / real_world_width}")
print(f"Pixel per mm (height): {scaled_img.shape[0] / real_world_height}")
