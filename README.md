# selfDefineaNameIfNVPsAreNotSuppliedForCereal
define your Names for which will be automatically created if NVPs are not supplied.

if you want set "value0" to a defined name by yourself what you need is `archive.setNextName("yourname");`

before

```
{
    "value0": {
        "data": {
            "ptr_wrapper": {
                "id": 0
            }
        }
    }
}
```

after

```
{
    "theNextItemNameIfNotExistButYouWantDefineIt": {
        "data": {
            "ptr_wrapper": {
                "id": 0
            }
        }
    }
}
```


# end./
