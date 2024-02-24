function solution(s) {
    let array=s.split(' ');
    let number=array.map(Number);
    let min=number[0];
    let max=number[0];
    number.forEach((e)=>{
        min=Math.min(min,e);
        max=Math.max(max,e);
    })
    return `${min} ${max}`;
}