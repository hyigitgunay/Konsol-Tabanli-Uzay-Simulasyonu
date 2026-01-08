#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PLANET_COUNT 8
#define PI 3.14159265358979323846
#define ABS_TERNARY(x) ((x) < 0.0 ? -(x) : (x))

/*Yardımcı Fonksiyonlar (Girdi okuma)*/

static void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* buffer temizle */ }
}

/* scanf başarısız olursa tekrar ister */
static double readDouble(const char *prompt) {
    double val;
    int ok;

    for (;;) {
        printf("%s", prompt);
        ok = scanf("%lf", &val);
        if (ok == 1) {
            clearInputBuffer();
            return val;
        }
        printf("HATA: Sayisal bir deger girmelisiniz. Tekrar deneyin.\n");
        clearInputBuffer();
    }
}

/*SADECE ternary ile mutlak değere çevirme (kütle/uzunluk/süre/hacim için) */
static double readNonNegativeMassKg(void) {
    double m = readDouble("KUTLE (m) [kg] giriniz: ");
    m = ABS_TERNARY(m);
    return m;
}

static double readNonNegativeLengthM(const char *prompt) {
    double L = readDouble(prompt);
    L = ABS_TERNARY(L);
    return L;
}

static double readNonNegativeTimeS(void) {
    double t = readDouble("SURE (t) [s] giriniz: ");
    t = ABS_TERNARY(t);
    return t;
}

static double readNonNegativeVolumeM3(void) {
    double V = readDouble("HACIM (V) [m^3] giriniz: ");
    V = ABS_TERNARY(V);
    return V;
}

/* ---------- Sunum / Menü ---------- */

static void printHeader(const char *scientistName) {
    printf("\n============================================================\n");
    printf("   KONSOL TABANLI UZAY SIMULASYONU - Fizik Deneyleri\n");
    printf("   Bilim Insani: %s\n", scientistName);
    printf("============================================================\n");
}

static void printMenu(void) {
    printf("\n-------------------- DENEY MENUSU --------------------------\n");
    printf("  1) Serbest Dusme Deneyi\n");
    printf("  2) Yukari Atis Deneyi\n");
    printf("  3) Agirlik Deneyi\n");
    printf("  4) Potansiyel Enerji Deneyi\n");
    printf("  5) Hidrostatik Basinç Deneyi\n");
    printf("  6) Arşimet Kaldirma Kuvveti Deneyi\n");
    printf("  7) Basit Sarkac Periyodu Deneyi\n");
    printf("  8) Sabit Ip Gerilmesi Deneyi\n");
    printf("  9) Asansor Deneyi\n");
    printf(" -1) Cikis\n");
    printf("------------------------------------------------------------\n");
}

/* ---------- Deney Fonksiyonları (Her biri ayrı) ---------- */

static void expFreeFall(const char *name, const char **planetNames, const double *gPtr, double t) {
    int i;
    printf("\n[1] SERBEST DUSME DENEYI (h = 0.5 * g * t^2)\n");
    printf("Girdi: t = %.4f s\n\n", t);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double h = 0.5 * g * t * t;
        printf("Sayin %s, %s gezegenindeki sonucunuz: h = %.4f m\n",
               name, *(planetNames + i), h);
    }
}

static void expUpwardThrow(const char *name, const char **planetNames, const double *gPtr, double v0) {
    int i;
    printf("\n[2] YUKARI ATIS DENEYI (h_max = v0^2 / (2g))\n");
    printf("Girdi: v0 = %.4f m/s\n\n", v0);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i); /* <-- POINTER ARITMETIGI */
        double hMax = (v0 * v0) / (2.0 * g);
        printf("Sayin %s, %s gezegenindeki sonucunuz: h_max = %.4f m\n",
               name, *(planetNames + i), hMax);
    }
}

static void expWeight(const char *name, const char **planetNames, const double *gPtr, double m) {
    int i;
    printf("\n[3] AGIRLIK DENEYI (G = m * g)\n");
    printf("Girdi: m = %.4f kg\n\n", m);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double G = m * g;
        printf("Sayin %s, %s gezegenindeki sonucunuz: G = %.4f N\n",
               name, *(planetNames + i), G);
    }
}

static void expPotentialEnergy(const char *name, const char **planetNames, const double *gPtr, double m, double h) {
    int i;
    printf("\n[4] POTANSIYEL ENERJI DENEYI (Ep = m * g * h)\n");
    printf("Girdiler: m = %.4f kg, h = %.4f m\n\n", m, h);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double Ep = m * g * h;
        printf("Sayin %s, %s gezegenindeki sonucunuz: Ep = %.4f J\n",
               name, *(planetNames + i), Ep);
    }
}

static void expHydrostaticPressure(const char *name, const char **planetNames, const double *gPtr, double rho, double h) {
    int i;
    printf("\n[5] HIDROSTATIK BASINC DENEYI (P = rho * g * h)\n");
    printf("Girdiler: rho = %.4f kg/m^3, h = %.4f m\n\n", rho, h);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double P = rho * g * h;
        printf("Sayin %s, %s gezegenindeki sonucunuz: P = %.4f Pa\n",
               name, *(planetNames + i), P);
    }
}

static void expBuoyantForce(const char *name, const char **planetNames, const double *gPtr, double rho, double V) {
    int i;
    printf("\n[6] ARSIMET KALDIRMA KUVVETI DENEYI (Fk = rho * g * V)\n");
    printf("Girdiler: rho = %.4f kg/m^3, V = %.6f m^3\n\n", rho, V);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double Fk = rho * g * V;
        printf("Sayin %s, %s gezegenindeki sonucunuz: Fk = %.4f N\n",
               name, *(planetNames + i), Fk);
    }
}

static void expPendulumPeriod(const char *name, const char **planetNames, const double *gPtr, double L) {
    int i;
    printf("\n[7] BASIT SARKAC PERIYODU DENEYI (T = 2*pi*sqrt(L/g))\n");
    printf("Girdi: L = %.4f m\n\n", L);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double T = 2.0 * PI * sqrt(L / g);
        printf("Sayin %s, %s gezegenindeki sonucunuz: T = %.4f s\n",
               name, *(planetNames + i), T);
    }
}

static void expRopeTension(const char *name, const char **planetNames, const double *gPtr, double m) {
    int i;
    printf("\n[8] SABIT IP GERILMESI DENEYI (T = m * g)\n");
    printf("Girdi: m = %.4f kg\n\n", m);

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double T = m * g;
        printf("Sayin %s, %s gezegenindeki sonucunuz: T = %.4f N\n",
               name, *(planetNames + i), T);
    }
}

static void expElevator(const char *name, const char **planetNames, const double *gPtr, double a, double m, int mode) {
    /* mode:
       1 => Yukari hizlanma / Asagi yavaslama : N = m(g + a)
       2 => Asagi hizlanma / Yukari yavaslama : N = m(g - a)
    */
    int i;
    printf("\n[9] ASANSOR DENEYI\n");
    printf("Girdiler: m = %.4f kg, a = %.4f m/s^2, mod = %d\n", m, a, mode);
    printf("Aciklama: Mod 1 => N = m(g + a), Mod 2 => N = m(g - a)\n\n");

    for (i = 0; i < PLANET_COUNT; ++i) {
        double g = *(gPtr + i);
        double N = (mode == 1) ? (m * (g + a)) : (m * (g - a)); /* ternary burada serbest */
        printf("Sayin %s, %s gezegenindeki sonucunuz: N = %.4f N\n",
               name, *(planetNames + i), N);
    }
}

/* ---------- Main ---------- */

int main(void) {
    /* Gezegen isimleri */
    const char *planetNames[PLANET_COUNT] = {
        "Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"
    };

    /* Yerçekimi ivmeleri (m/s^2) — dizi içinde tutulur, ERİŞİM pointer ile olacak */
    double gArray[PLANET_COUNT] = { 3.7, 8.87, 9.8, 3.71, 24.79, 10.44, 8.69, 11.15 };
    const double *gPtr = gArray; /* Fonksiyonlara pointer olarak gönderilecek */

    char scientistName[64];
    int choice;

    printf("Bilim Insani Adi giriniz: ");
    if (fgets(scientistName, (int)sizeof(scientistName), stdin) == NULL) {
        printf("HATA: Isim okunamadi.\n");
        return 1;
    }
    /* newline temizle */
    scientistName[strcspn(scientistName, "\n")] = '\0';

    for (;;) {
        printHeader(scientistName);
        printMenu();

        printf("Deney seciminiz (1-9) / Cikis icin -1: ");
        if (scanf("%d", &choice) != 1) {
            printf("HATA: Gecersiz secim. Lutfen sayi giriniz.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        if (choice == -1) {
            printf("\nCikis yapiliyor... Iyi calismalar, %s!\n", scientistName);
            break;
        }

        switch (choice) {
            case 1: {
                double t = readNonNegativeTimeS(); /* sure: ternary ile mutlak */
                expFreeFall(scientistName, planetNames, gPtr, t);
                break;
            }
            case 2: {
                double v0 = readDouble("ILK HIZ (v0) [m/s] giriniz: ");
                expUpwardThrow(scientistName, planetNames, gPtr, v0);
                break;
            }
            case 3: {
                double m = readNonNegativeMassKg(); /* kutle: ternary ile mutlak */
                expWeight(scientistName, planetNames, gPtr, m);
                break;
            }
            case 4: {
                double m = readNonNegativeMassKg(); /* kutle: ternary */
                double h = readNonNegativeLengthM("YUKSEKLIK (h) [m] giriniz: "); /* uzunluk: ternary */
                expPotentialEnergy(scientistName, planetNames, gPtr, m, h);
                break;
            }
            case 5: {
                double rho = readDouble("YOGUNLUK (rho) [kg/m^3] giriniz: ");
                double h = readNonNegativeLengthM("DERINLIK (h) [m] giriniz: "); /* uzunluk: ternary */
                expHydrostaticPressure(scientistName, planetNames, gPtr, rho, h);
                break;
            }
            case 6: {
                double rho = readDouble("YOGUNLUK (rho) [kg/m^3] giriniz: ");
                double V = readNonNegativeVolumeM3(); /* hacim: ternary */
                expBuoyantForce(scientistName, planetNames, gPtr, rho, V);
                break;
            }
            case 7: {
                double L = readNonNegativeLengthM("IP UZUNLUGU (L) [m] giriniz: "); /* uzunluk: ternary */
                expPendulumPeriod(scientistName, planetNames, gPtr, L);
                break;
            }
            case 8: {
                double m = readNonNegativeMassKg(); /* kutle: ternary */
                expRopeTension(scientistName, planetNames, gPtr, m);
                break;
            }
            case 9: {
                double a = readDouble("ASANSOR IVMESI (a) [m/s^2] giriniz: ");
                double m = readNonNegativeMassKg(); /* kutle: ternary */

                printf("YON/MOD seciniz:\n");
                printf("  1) Yukari hizlanma / Asagi yavaslama   (N = m(g + a))\n");
                printf("  2) Asagi hizlanma / Yukari yavaslama   (N = m(g - a))\n");

                int mode;
                for (;;) {
                    printf("Seciminiz (1/2): ");
                    if (scanf("%d", &mode) == 1 && (mode == 1 || mode == 2)) {
                        clearInputBuffer();
                        break;
                    }
                    printf("HATA: Sadece 1 veya 2 girebilirsiniz.\n");
                    clearInputBuffer();
                }

                expElevator(scientistName, planetNames, gPtr, a, m, mode);
                break;
            }
            default:
                printf("\nUYARI: 1-9 arasi bir deger giriniz veya cikis icin -1.\n");
                break;
        }

        printf("\nDevam etmek icin ENTER'a basin...");
        getchar();
    }

    return 0;
}
