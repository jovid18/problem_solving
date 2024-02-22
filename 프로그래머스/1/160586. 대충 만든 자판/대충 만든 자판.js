function solution(keymap, targets) {
  let ans = [];
  let m = new Map();
  for (let i = 0; i < keymap.length; ++i) {
    let key = keymap[i];
    for (let j = 0; j < key.length; ++j) {
      if (m.has(key[j])) {
        m.set(key[j], Math.min(m.get(key[j]), j + 1));
      } else {
        m.set(key[j], j + 1);
      }
    }
  }
  for (let i = 0; i < targets.length; ++i) {
    let target = targets[i];
    let now = 0;
    for (let j = 0; j < target.length; ++j) {
      if (m.has(target[j])) {
        if (now !== -1) now += m.get(target[j]);
      } else {
        now = -1;
      }
    }
    ans.push(now);
  }
  return ans;
}