process.stdin.setEncoding('utf8');
process.stdin.on('data', (data) => {
  // 직사각형 별찍기
  // 2중 for문 사용
  const n = data.split(' ');
  const a = Number(n[0]),
    b = Number(n[1]);
  for (let i = 0; i < b; i++) {
    console.log('*'.repeat(a));
  }
  // console.log(a);
  // console.log(b);
});
