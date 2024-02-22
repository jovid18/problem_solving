function solution(wallpaper) {
  let minX = 100,
    minY = 100,
    maxX = -1,
    maxY = -1;
  wallpaper.forEach((e, x) => {
    [...e].forEach((f, y) => {
      if (f == "#") {
        maxX = Math.max(x, maxX);
        maxY = Math.max(y, maxY);
        minX = Math.min(x, minX);
        minY = Math.min(y, minY);
      }
    });
  });
  let answer = [minX, minY, maxX + 1, maxY + 1];
  return answer;
}