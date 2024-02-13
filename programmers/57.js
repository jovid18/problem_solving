function solution(s, skip, index) {
  ans = "";
  const AtoN = {},
    NtoA = {};
  for (let i = 0; i < 26; i++) {
    AtoN[String.fromCharCode(97 + i)] = i;
    NtoA[i] = String.fromCharCode(97 + i);
  }
  let skips = new Set();
  [...skip].forEach((e) => {
    skips.add(e);
  });
  [...s].forEach((e) => {
    let cnt = index;
    let now = e;
    while (cnt != 0) {
      now = NtoA[(AtoN[now] + 1) % 26];
      if (!skips.has(now)) cnt--;
    }
    ans += now;
  });
  return ans;
}
let s = "aukks";
let skip = "wbqd";
let index = 5;

solution(s, skip, index);
