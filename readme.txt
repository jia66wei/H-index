基于H-index的用户质量评测: 

H-index算法：http://en.wikipedia.org/wiki/H-index 

注  H-index：用户最多有N个粉丝的粉丝数大于N

前二十名的结果： 

1. 头条新闻 2. 李开复 3. 新周刊 4. 作业本 5. 微博iphone客户端 6. 姚晨 7. 蔡康永 8. 微博小秘书 9. 潘石屹 10. 小S 11. 韩寒 12. 微博android客户端 13. veggieg 14. 薛蛮子 15. 三联生活周刊 16. WEIKAN助手 17 李承鹏 18. 任志强 19. 企业微博助手 20. 南方周末

运行：

./H_index ${fansNum} ${fansUid} >> H_index_all.txt

fansNum 格式： uid\tnums
fansUid 格式： uid\tfans1,fans2,....
