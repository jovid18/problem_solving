function solution(price, money, count) {

  let totalprice = price * ((count * (count + 1)) / 2); 
  return Math.max(totalprice - money, 0);

}
