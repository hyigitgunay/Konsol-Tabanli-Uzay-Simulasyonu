# 🚀 Konsol Tabanlı Uzay Simülasyonu

**Bursa Teknik Üniversitesi - Bilgisayar Mühendisliği**  
**Algoritmalar ve Programlama Dersi Projesi**  
**2025-2026 Güz Dönemi**

---

## 📝 Proje Hakkında

Bu proje, C programlama dili kullanılarak geliştirilmiş konsol tabanlı bir uzay simülasyonu uygulamasıdır. Güneş sistemindeki 8 farklı gezegen üzerinde 9 farklı fizik deneyinin simülasyonunu gerçekleştirmektedir.

**Bu proje bireysel olarak geliştirilmiştir.**

---

## 👨‍🔬 Geliştirici

| Bilgi | Değer |
|-------|-------|
| **Ad Soyad** | Hikmet Yiğit Günay |
| **Öğrenci No** | 23360859060 |
| **Bölüm** | Bilgisayar Mühendisliği |
| **Üniversite** | Bursa Teknik Üniversitesi |

---

## 🔬 Desteklenen Deneyler

| No | Deney Adı | Formül |
|----|-----------|--------|
| 1 | Serbest Düşme | `h = ½ × g × t²` |
| 2 | Yukarı Atış | `h_max = v₀² / (2g)` |
| 3 | Ağırlık Hesaplama | `G = m × g` |
| 4 | Potansiyel Enerji | `Ep = m × g × h` |
| 5 | Hidrostatik Basınç | `P = ρ × g × h` |
| 6 | Arşimet Kaldırma Kuvveti | `Fk = ρ × g × V` |
| 7 | Basit Sarkaç Periyodu | `T = 2π × √(L/g)` |
| 8 | Sabit İp Gerilmesi | `T = m × g` |
| 9 | Asansör Deneyi | `N = m(g ± a)` |

---

## 🌍 Desteklenen Gezegenler

| Gezegen | Yerçekimi İvmesi (m/s²) |
|---------|-------------------------|
| Merkür | 3.70 |
| Venüs | 8.87 |
| Dünya | 9.80 |
| Mars | 3.71 |
| Jüpiter | 24.79 |
| Satürn | 10.44 |
| Uranüs | 8.69 |
| Neptün | 11.15 |

---

## ⚙️ Teknik Özellikler

- **Dil:** C (ANSI C99)
- **Dizi Erişimi:** Pointer aritmetiği (`*(ptr + i)`)
- **Negatif Değer Kontrolü:** Ternary operatör kullanımı
- **Modüler Yapı:** Her deney ayrı fonksiyonda
- **Menü Sistemi:** Switch-case yapısı

---

## 🛠️ Derleme ve Çalıştırma

### Windows (GCC/MinGW)
```bash
gcc -o main main.c -lm
./main.exe
```

### Linux/macOS
```bash
gcc -o main main.c -lm
./main
```

---

## 📸 Ekran Görüntüleri

### Program Açılışı
```
Bilim Insani Adi giriniz: [İsminizi girin]

============================================================
   KONSOL TABANLI UZAY SIMULASYONU - Fizik Deneyleri
   Bilim Insani: [İsminiz]
============================================================
```

### Deney Menüsü
```
-------------------- DENEY MENUSU --------------------------
  1) Serbest Dusme Deneyi
  2) Yukari Atis Deneyi
  3) Agirlik Deneyi
  4) Potansiyel Enerji Deneyi
  5) Hidrostatik Basinç Deneyi
  6) Arşimet Kaldirma Kuvveti Deneyi
  7) Basit Sarkac Periyodu Deneyi
  8) Sabit Ip Gerilmesi Deneyi
  9) Asansor Deneyi
 -1) Cikis
------------------------------------------------------------
```

---

## 📄 Proje Yapısı

```
📁 Konsol-Tabanli-Uzay-Simulasyonu/
├── 📄 main.c              # Ana kaynak kodu
├── 📄 README.md           # Bu dosya
├── 📄 .gitignore          # Git ignore dosyası
└── 📄 LICENSE             # Lisans (isteğe bağlı)
```

---

## 📚 Kaynaklar

- Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language* (2nd ed.). Prentice Hall.
- NASA Planetary Fact Sheet: https://nssdc.gsfc.nasa.gov/planetary/factsheet/

---

## 📜 Lisans

Bu proje eğitim amaçlı geliştirilmiştir.  
© 2025 Hikmet Yiğit Günay - Bursa Teknik Üniversitesi
