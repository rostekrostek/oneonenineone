import wikipedia
def checklang(language):
    if (arr[-1] in wikipedia.languages()):
      return 1
    else:
      return 0


def maxword(arr):
    titlemax=''
    maxword1=0
    for i in range(len(arr)):
      pagei= wikipedia.page(arr[i])
      shorts=pagei.summary
      if len(shorts.split()) >= maxword1:
        maxword1=len(shorts.split())
        titlemax=pagei.title
    return maxword1, titlemax 


def chains(arr):
    chain= [arr[0]]
    for i in range(len(arr)-1):
        newpage=wikipedia.page(arr[i])
        if arr[i+1] in newpage.links:
            chain.append(arr[i+1])
        else:
            for j in range(len(newpage.links)):
                newpage1=wikipedia.page(newpage.links[j])
                if arr[i+1] in newpage1.links:
                    chain.append(newpage.links[j])
                    chain.append(arr[i+1])
                    break		
    return chain
 
inn= input()
arr=inn.split(', ')
if (checklang(arr[-1])):
  wikipedia.set_lang(arr[-1])
  arr.remove(arr[-1])
  maxend=maxword(arr)
  print(maxend[0], maxend[1])
  print(chains(arr))
else:
    print("no results")
  
