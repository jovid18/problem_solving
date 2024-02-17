function solution(park, routes) {
  let dir = { E: [0, 1], W: [0, -1], N: [-1, 0], S: [1, 0] };
  let pos = [0, 0];
  park.forEach((e, xidx) => {
    park.forEach((f, yidx) => {
      if (park[xidx][yidx] === "S") {
        pos[0] = xidx;
        pos[1] = yidx;
      }
    });
  });
  let H = park.length;
  let W = park[0].length;
  routes.forEach((e) => {
    let [op, n] = e.split(" ");
    let isValid = true;
    let fpos = [pos[0] + n * dir[op][0], pos[1] + n * dir[op][1]];
    if (fpos[0] < 0 || fpos[1] < 0 || fpos[0] >= H || fpos[1] >= W) isValid = false;
    if (isValid) {
      for (let d = 1; d <= n; ++d) {
        let npos = [pos[0] + d * dir[op][0], pos[1] + d * dir[op][1]];
        if (park[npos[0]][npos[1]] === "X") isValid = false;
      }
    }
    if (isValid) pos = fpos;
  });

  return [pos[0], pos[1]];
}
