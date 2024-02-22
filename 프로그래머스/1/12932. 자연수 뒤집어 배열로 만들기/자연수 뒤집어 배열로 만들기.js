function solution(n) {
  let a = String(n).split('');
  a.reverse();
  return a.map((e) => {
    return Number(e);
  });
}

