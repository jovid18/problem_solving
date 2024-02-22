function solution(sizes) {
  var answer = 0;
  let maxw = 0;
  let maxh = 0;
  sizes.forEach((e) => {
    maxh = Math.max(maxh, Math.max(e[0], e[1]));
    maxw = Math.max(maxw, Math.min(e[0], e[1]));
  });

  return maxw * maxh;
}
