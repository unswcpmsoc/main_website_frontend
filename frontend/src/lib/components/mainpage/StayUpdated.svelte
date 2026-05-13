<script lang="ts">
    import Stay_Updated from '$lib/assets/stayupdated/BackgroundStayUpdated.webp'
    import Sand_Solid_Colour_Stay_Updated from '$lib/assets/stayupdated/SandSolidColourStayUpdated.webp'

    import Paper_Swan from '$lib/assets/stayupdated/PaperSwan.webp'
    import Paper_Swan_Background from '$lib/assets/stayupdated/PaperSwanBackground.webp'

    let tiltX = $state(0);
    let tiltY = $state(0);

    const handleMouseMove = (e: MouseEvent) => {
        if (e == null || !e.currentTarget) { return }

        const target = e.currentTarget as HTMLElement
        const rect = target.getBoundingClientRect();
        const x = e.clientX - rect.left - rect.width / 2;
        const y = e.clientY - rect.top - rect.height / 2;

        tiltX = -y / 80;
        tiltY = x / 80;
    }

    const handleMouseLeave = () => {
        tiltX = 0;
        tiltY = 0;
    }
</script>

<div class="relative flex w-full md:h-[750px] h-[800px] items-center overflow-hidden justify-center p-[20px]">

    <img
            src={Stay_Updated}
            alt=""
            class="absolute inset-0 h-full w-full object-fill pointer-events-none select-none"
    />

    <div class="relative w-full h-full z-10 shadow-2xl overflow-hidden">

        <img
                src={Sand_Solid_Colour_Stay_Updated}
                alt="Sand Background"
                class="absolute inset-0 h-full w-full object-cover pointer-events-none select-none -z-10 brightness-110"
        />

        <div class="hidden lg:flex absolute top-3 right-0 pointer-events-none select-none z-10 flex-col items-end">
            <svg class="absolute inset-0 w-[240px] h-full -translate-x-20 -translate-y-8">
                <defs>
                    <pattern id="x-pattern-two" width="60" height="60" patternUnits="userSpaceOnUse">
                        <path d="M15 15L25 25M25 15L15 25" stroke="#5e508a" stroke-width="1.2" opacity="0.25"/>

                        <path d="M45 45L55 55M55 45L45 55" stroke="#5e508a" stroke-width="1.2" opacity="0.25"/>
                    </pattern>
                </defs>
                <rect width="100%" height="100%" fill="url(#x-pattern-two)" />
            </svg>

            <p class="font-mono text-[20px] text-[#5e508a] opacity-60 px-2 translate-y-16 z-10 relative">
                10001010101110101101010101
            </p>

            <div
                    class="w-70 h-18 opacity-100 z-5"
                    style="background: linear-gradient(to right, #a5a8d9, #8988ca);"
            ></div>
        </div>

        <div class="flex flex-col md:flex-row w-full h-full">

            <div class="flex-1 flex flex-col justify-center px-8 md:px-20 xl:pl-30 gap-5 md:mt-12 lg:ml-0">

                <div class="hidden md:block absolute -top-10 -left-10 pointer-events-none select-none z-0 overflow-visible"
                     style="transform: rotate(-15deg); width: 240px; height: 150px;">

                    <svg class="absolute inset-0 w-full h-full lg:-translate-y-0 -translate-y-3" viewBox="0 0 200 120">
                        <rect x="1" y="1" width="198" height="118" fill="none" stroke="#5e508a" stroke-width="1.2" stroke-dasharray="5 5" opacity="0.4"/>
                    </svg>

                    <svg class="absolute inset-0 w-full h-full -translate-x-2 lg:-translate-y-2 -translate-y-5">
                        <defs>
                            <pattern id="x-pattern" width="60" height="60" patternUnits="userSpaceOnUse">
                                <path d="M15 15L25 25M25 15L15 25" stroke="#5e508a" stroke-width="1.2" opacity="0.25"/>

                                <path d="M45 45L55 55M55 45L45 55" stroke="#5e508a" stroke-width="1.2" opacity="0.25"/>
                            </pattern>
                        </defs>
                        <rect width="100%" height="100%" fill="url(#x-pattern)" />
                    </svg>
                </div>

                <div class="hidden md:block absolute lg:top-33 top-28 left-0 pointer-events-none opacity-75 select-none z-0">
                    <p class="font-mono text-[14px] text-[#5e508a] opacity-60 mb-2 px-10">
                        float Q_rsqrt(void) &#123; i  = 0x5f3759df - ( i >> 1 ); &#125;
                    </p>

                    <div
                            class="w-70 h-7"
                            style="background: linear-gradient(to right, #a6a8d9, #7d7ac4);"
                    ></div>
                </div>

                <div
                        class="absolute left-4 bottom-0 top-0 flex items-center pointer-events-none select-none"
                        style="writing-mode: vertical-rl; transform: rotate(180deg);"
                >
                    <p class="font-mono text-[12px] md:text-base tracking-widest opacity-20 text-black/75 uppercase">
                        0100001101001111010011010101000001010011
                    </p>
                </div>

                <h2 class="text-5xl md:text-6xl lg:text-7xl font-bold tracking-tight pt-5">
                    Stay Updated
                </h2>

                <p class="font-mono text-xs md:text-[14px] leading-relaxed">
                    Follow us on Facebook and subscribe to our Google
                    Calendar to hear about all our exciting events. On our
                    Discord server, you can receive event updates as well as chat
                    with other members!
                </p>

                <div class="flex flex-wrap gap-3 mt-2">
                    <a
                            href="https://www.facebook.com/CPMSoc/"
                            target="_blank"
                            rel="noreferrer noopener"
                            class="bg-[#1a1a1a] text-white font-mono text-sm py-2 px-4 hover:bg-black transition-colors"
                    >
                        Facebook
                    </a>

                    <a
                            href="https://www.instagram.com/cpmsoc_unsw/?hl=en"
                            target="_blank"
                            rel="noreferrer noopener"
                            class="bg-[#1a1a1a] text-white font-mono text-sm py-2 px-4 hover:bg-black transition-colors"
                    >
                        Instagram
                    </a>

                    <a
                            href="https://calendar.google.com/calendar/u/0/r?cid=Y19mNDVmMzdjOGQzM2U2MGNlMDE4ZmMwZWU2MjcyNDdkN2Y3ODI3NDFmMmZiNmRjYjIxYjA5ZWU4YjRlYWY1YTFjQGdyb3VwLmNhbGVuZGFyLmdvb2dsZS5jb20"
                            target="_blank"
                            rel="noreferrer noopener"
                            class="bg-[#1a1a1a] text-white font-mono text-sm py-2 px-4 hover:bg-black transition-colors"
                    >
                        Google Calendar
                    </a>

                    <a
                            href="https://discord.com/invite/9uxgxHY3pP"
                            target="_blank"
                            rel="noreferrer noopener"
                            class="bg-[#1a1a1a] text-white font-mono text-sm py-2 px-4 hover:bg-black transition-colors"
                    >
                        Discord
                    </a>
                </div>
            </div>

            <div class="flex-1 flex items-center justify-center perspective-[750px] xl:pr-36 md:mr-10 sm:mb-0 mb-5 md:mt-12">
                <div
                        class="brightness-105 relative w-[80%] sm:w-[60%] md:w-[90%] max-w-[500px] aspect-square transition-transform duration-1000 ease-out will-change-transform"
                        role="presentation"
                        onmousemove={handleMouseMove}
                        onmouseleave={handleMouseLeave}
                        style="transform: rotateX({tiltX}deg) rotateY({tiltY}deg)"
                >
                    <img
                            src={Paper_Swan_Background}
                            alt="Grid Background"
                            class="absolute inset-0 w-full h-full object-contain translate-x-2 translate-y-2"
                            style="transform: translateX({-tiltY * 0.5}px) translateY({-tiltX * 0.5}px)"
                    />

                    <svg
                            class="absolute inset-0 w-full h-full pointer-events-none z-0 opacity-70 mix-blend-multiply scale-95 -translate-x-10 -translate-y-2"
                            viewBox="0 0 500 500"
                            style="transform: translateX({-tiltY}px) translateY({-tiltX}px) translateZ(10px)"
                    >
                        <defs>
                            <linearGradient id="mathGradient" x1="0" y1="0" x2="1" y2="1">
                                <stop offset="0%" stop-color="#7c3aed" />
                                <stop offset="100%" stop-color="#4f46e5" />
                            </linearGradient>

                            <path id="innerCircle" d="M 250, 250 m -135, 0 a 135,135 0 1,1 270,0 a 135,135 0 1,1 -270,0" />
                            <path id="outerCircle" d="M 250, 250 m -180, 0 a 180,180 0 1,1 360,0 a 180,180 0 1,1 -360,0" />
                        </defs>

                        <g style="transform-origin: 250px 250px; animation: spinMath 80s linear infinite;">
                            <text class="font-mono font-bold text-[10px] tracking-[2px]" fill="url(#mathGradient)">
                                <textPath href="#innerCircle">
                                    f(x)=x^2∫_a^bf(t)dt=F(b)-F(a)σ_x^2=E[(X-μ)^2]∑_[n=0]^∞(x^n)/n!=e^x∇⋅E=ρ/ε(ε&gt;0,δ&gt;0)|x-c|&lt;δ→|f(x)-L|&lt;εlim_(h→0)(f(x+h)-f(x))/h=f'(x)e^(iπ)+1=0sin^2θ+cos^2θ=1x=(-b±√(b^2-4ac))/2a∮E⋅dA=Q/ε_0∇×B=μ_0J+μ_0ε_0∂E/∂tiℏ∂ψ/∂t=HψF=dp/dtE=mc^2S=k_blnΩPV=nRTa^2+b^2=c^2
                                </textPath>
                            </text>
                        </g>

                        <g style="transform-origin: 250px 250px; animation: spinMath 100s linear infinite reverse;">
                            <text class="font-mono font-bold text-[11px] tracking-[3px]" fill="url(#mathGradient)" opacity="0.6">
                                <textPath href="#outerCircle">
                                    εlim_(h→0)(f(x+h)-f(x))/h=f'(x)e^(iπ)+1=0sin^2θ+cos^2θ=1x=(-b±√(b^2-4ac))/2a∮E⋅dA=Q/ε_0∇×B=μ_0J+μ_0ε_0∂E/∂tiℏ∂ψ/∂t=HψF=dp/dtE=mc^2S=k_blnΩPV=nRTa^2+b^2=c^2f(x)=x^2∫_a^bf(t)dt=F(b)-F(a)σ_x^2=E[(X-μ)^2]∑_[n=0]^∞(x^n)/n!=e^x∇⋅E=ρ/ε(ε&gt;0,δ&gt;0)|x-c|&lt;δ→|f(x)-L|&lt;
                                </textPath>
                            </text>
                        </g>

                        <style>
                            @keyframes spinMath {
                                from { transform: rotate(0deg); }
                                to { transform: rotate(360deg); }
                            }
                        </style>
                    </svg>
                    <img
                            src={Paper_Swan}
                            alt="Paper Swan"
                            class="absolute inset-0 w-full h-full object-contain z-10 drop-shadow-2xl"
                            style="transform: translateX({-tiltY * 1.5}px) translateY({-tiltX * 1.5}px) translateZ(20px)"
                    />
                </div>
            </div>

            <!-- Bottom right circle-->
            <svg
                    class="absolute bottom-0 right-0 xl:w-[15%] w-[20%] h-auto pointer-events-none select-none z-0"
                    viewBox="0 0 100 100"
            >
                <circle
                        cx="100"
                        cy="100"
                        r="75"
                        fill="#d9c5cc"
                        opacity="0.3"
                />

                <circle
                        cx="100"
                        cy="100"
                        r="85"
                        fill="none"
                        stroke="#5e508a"
                        stroke-width="1.2"
                        stroke-dasharray="4 4"
                        opacity="0.6"
                />
<!--                <text-->
<!--                        x="62"-->
<!--                        y="90"-->
<!--                        fill="#645a9e"-->
<!--                        font-family="font-instrument-sans"-->
<!--                        font-weight="bold"-->
<!--                        font-size="12"-->
<!--                        text-anchor="middle"-->
<!--                        letter-spacing="1.5"-->
<!--                        class="opacity-100"-->
<!--                >-->
<!--                    &gt;&gt;&gt;&gt;&gt;&gt;-->
<!--                </text>-->
            </svg>
        </div>
    </div>
</div>