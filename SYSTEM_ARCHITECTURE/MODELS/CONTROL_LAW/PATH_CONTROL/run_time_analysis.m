imshow(track_map, [0 1]);
hold(gca, 'on');
axis on;
ax = gca;           % Get current axes handle
ax.XLim = [0 size(track_map, 2)];  % Set X-axis limits to image width (in pixels)
ax.YLim = [0 size(track_map, 1)];  % Set Y-axis limits to image height (in pixels)
sensor_3_coord
scatter(sensor_3_coord(1), sensor_3_coord(2), 100, 'filled')