function solution(n) {
  let a = String(n).split('');
  a.reverse();
  let b = a.map((e) => {
    return Number(e);
  });
  return b;
}
