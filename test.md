	```mermaid
	    sequenceDiagram
	    participant 张 as 张三
	    participant 李 as 李四
	    张 ->> 李: 你好！李四, 最近怎么样?
	    alt 如果感冒了
	    李->> 张: 不太好，生病了。
	    else 挺好的
	    李->> 张: 我很好，谢谢。
	    end
	        opt 另外补充
	        李->> 张: 谢谢问候。
	    end
```
